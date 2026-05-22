/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_life
*/

#include <stdio.h>
#include <SFML/Graphics.h>

#include "interface.h"
#include "struct/game.h"

void update_life(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    char result[MAX_LIFE_LABEL_LEN];

    sprintf(result, LIFE_LABEL_FORMAT, game->plr.life);
    sfText_setString(text, result);
}

void update_volume_text(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    char result[MAX_LIFE_LABEL_LEN];

    sprintf(result, VOLUME_LABEL_FORMAT, (size_t)game->settings.music_volume);
    sfText_setString(text, result);
}

void update_fov_text(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    char result[MAX_LIFE_LABEL_LEN];

    sprintf(result, FOV_LABEL_FORMAT, (size_t)game->settings.fov);
    sfText_setString(text, result);
}

void update_fullscreen_text(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;

    sfText_setString(text, game->settings.fullscreen ?
        "fullscreen" : "windowed");
}
