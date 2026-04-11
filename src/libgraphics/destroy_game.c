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

//! sfSprite_destroy crash if texture loading fail
static void destroy_entitys(entity_sprite_t *entity)
{
    for (entity_id_t id = 0; id < NB_ENT; id++) {
        if (entity[id].texture != NULL)
            sfTexture_destroy(entity[id].texture);
        if (entity[id].sprite != NULL)
            sfSprite_destroy(entity[id].sprite);
    }
}

void destroy_game(game_t *game)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->clock != NULL)
        sfClock_destroy(game->clock);
    if (game->event != NULL)
        free(game->event);
    destroy_entitys(game->entity);
}
