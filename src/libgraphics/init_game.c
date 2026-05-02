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
#include <SFML/Graphics/Font.h>
#include "macro.h"
#include "graphics.h"

static int init_sprite(component_ressource_t *ressource, char *texture_path)
{
    ressource->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!ressource->texture)
        return ERROR;
    ressource->sprite = sfSprite_create();
    if (!ressource->sprite)
        return ERROR;
    sfSprite_setTexture(ressource->sprite, ressource->texture,
        sfTrue);
    return SUCCESS;
}

static int init_font(component_ressource_t *ressource, char *font_path)
{
    ressource->font = sfFont_createFromFile(font_path);
    if (ressource->font == NULL)
        return ERROR;
    return SUCCESS;
}

static int init_sprite_list(component_ressource_t *sprite_list)
{
    int exit = SUCCESS;

    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++) {
        sprite_list[id].id = id;
        switch (RESSOURCE_LIST[id].type) {
            case TEXTURE:
                exit = init_sprite(&sprite_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
            case FONT:
                exit = init_font(&sprite_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
        }
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
