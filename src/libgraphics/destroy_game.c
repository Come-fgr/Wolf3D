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
static void destroy_entitys(component_sprite_t *sprite_list)
{
    for (entity_id_t id = 0; id < NB_ENT; id++) {
        if (sprite_list[id].texture != NULL)
            sfTexture_destroy(sprite_list[id].texture);
        if (sprite_list[id].sprite != NULL)
            sfSprite_destroy(sprite_list[id].sprite);
    }
}

void destroy_game(game_t *game)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->clock != NULL)
        sfClock_destroy(game->clock);
    destroy_entitys(game->sprite_list);
}
