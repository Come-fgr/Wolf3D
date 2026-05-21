/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Destroy game objects
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include "struct/game.h"

void free_ressource(ressource_t *ressource)
{
    if (ressource->data)
        RESSOURCE_DIR[ressource->type].destroy(ressource->data);
    if (ressource->name)
        free(ressource->name);
}

//TODO: destroy scene
void destroy_game(game_t *game)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->clock != NULL)
        sfClock_destroy(game->clock);
    free_list(*game->ressource_list, (void (*)(void *))free_ressource);
}
