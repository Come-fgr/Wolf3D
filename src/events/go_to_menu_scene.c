/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** go_to_pause_scene
*/

#include "struct/game.h"

void go_to_pause_scene(game_t *game)
{
    if (game == NULL)
        return;
    game->cur_scene = MENU_PAUSE;
}

void go_to_settings_scene(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    game->cur_scene = SETTINGS;
}
