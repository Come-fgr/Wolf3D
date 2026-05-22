/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** change_scene
*/

#include "config.h"
#include "struct/game.h"

void got_to_prev_scene(game_t *game, [[maybe_unused]] void *data)
{
    scene_id_t temp = game->prev_scene;

    if (game == NULL)
        return;
    if (game->prev_scene == NB_SCENE) {
        exit_game(game, NULL);
        return;
    }
    game->prev_scene = game->cur_scene;
    game->cur_scene = temp;
}

void go_to_settings_scene(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    game->prev_scene = game->cur_scene;
    game->cur_scene = SETTINGS;
}

void go_to_start_scene(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    game->prev_scene = NB_SCENE;
    game->cur_scene = MENU_START;
}
