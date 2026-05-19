/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "macro.h"
#include "graphics.h"

static int init_sprite_list(component_sprite_t *sprite_list)
{
    for (texture_id_t id = 0; id < NB_TEXTURE; id++) {
        sprite_list[id].id = id;
        sprite_list[id].texture = sfTexture_createFromFile(
            TEXTURE_LIST[id].texture_path, NULL);
        if (!sprite_list[id].texture)
            return ERROR;
        sprite_list[id].sprite = sfSprite_create();
        if (!sprite_list[id].sprite)
            return ERROR;
        sfSprite_setTexture(sprite_list[id].sprite, sprite_list[id].texture,
            sfTrue);
    }
    return SUCCESS;
}

static void init_player(player_t *plr)
{
    plr->pos = (sfVector2f){ 160.0f, 160.0f };
    plr->angle = (float)M_PI * 0.25f;
    plr->speed = DEFAULT_PLR_SPEED;
}

int init_game(game_t *game)
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->clock = sfClock_create();
    game->plr = (player_t){0};
    init_player(&game->plr);
    error += init_sprite_list(game->sprite_list);
    if (error || !game->window || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
