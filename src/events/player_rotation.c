/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_rotation
*/

#include "struct/game.h"

void player_rotate_right(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.rot_vel = 1;
}

void player_rotate_left(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.rot_vel = -1;
}

void player_rotate_stop(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.rot_vel = 0;
}
