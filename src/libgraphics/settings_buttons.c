/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** settings_buttons
*/

#include "struct/game.h"

void increase_music_volume(game_t *game, [[maybe_unused]] void *data)
{
    game->settings.music_volume += game->settings.music_volume >= MAX_VOLUME ?
        0 : 1;
}

void decrease_music_volume(game_t *game, [[maybe_unused]] void *data)
{
    game->settings.music_volume -= game->settings.music_volume <= MIN_VOLUME ?
        0 : 1;
}

void increase_fov(game_t *game, [[maybe_unused]] void *data)
{
    game->settings.fov += game->settings.fov >= MAX_FOV ? 0 : 1;
}

void decrease_fov(game_t *game, [[maybe_unused]] void *data)
{
    game->settings.fov -= game->settings.fov <= MIN_FOV ? 0 : 1;
}

void change_window_mode(game_t *game, [[maybe_unused]] void *data)
{
    game->settings.fullscreen = game->settings.fullscreen ? false : true;
}
