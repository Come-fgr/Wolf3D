/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_move
*/

#include "struct/game.h"

void player_move_stop_x(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.x = 0;
}

void player_move_stop_y(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.y = 0;
}
