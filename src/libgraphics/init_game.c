/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <stdlib.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "macro.h"
#include "graphics.h"

static int init_entity_sprite(entity_sprite_t *entity, entity_id_t id,
    char *texture_path)
{
    entity->id = id;
    entity->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!entity->texture)
        return ERROR;
    entity->sprite = sfSprite_create();
    if (!entity->sprite)
        return ERROR;
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    return SUCCESS;
}

int init_game(game_t *game)
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->event = malloc(sizeof(sfEvent));
    game->clock = sfClock_create();
    for (entity_id_t id = 0; id < NB_ENT; id++)
        error += init_entity_sprite(&game->entity[id], id,
            ENTITY[id].texture_path);
    if (error || !game->window || !game->event || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
