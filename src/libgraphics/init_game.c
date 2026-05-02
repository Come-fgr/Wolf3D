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

static int init_sprite(component_ressource_t *sprite, char *texture_path)
{
    sprite->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!sprite->texture)
        return ERROR;
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite)
        return ERROR;
    sfSprite_setTexture(sprite->sprite, sprite->texture,
        sfTrue);
    return SUCCESS;
}

static int init_sprite_list(component_ressource_t *sprite_list)
{
    int exit = SUCCESS;

    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++) {
        sprite_list[id].id = id;
        if (RESSOURCE_LIST[id].type == TEXTURE)
            exit = init_sprite(&sprite_list[id],
                RESSOURCE_LIST[id].ressource_path);
        if (exit == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int init_game(game_t *game)
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->event = malloc(sizeof(sfEvent));
    game->clock = sfClock_create();
    error += init_sprite_list(game->sprite_list);
    if (error || !game->window || !game->event || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
