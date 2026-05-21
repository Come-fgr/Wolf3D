/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_flashlight
*/

#include "struct/game.h"

void player_flashlight_toggle(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.flash = !game->plr.flash;
}
