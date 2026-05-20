/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** go_to_menu_scene
*/

#include "struct/game.h"

void go_to_menu_scene(game_t *game)
{
    if (game == NULL)
        return;
    game->cur_scene = MENU_START;
}
