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
    game->plr.angle += game->delta_time * PLR_ROTATE_VALUE;
}

void player_rotate_left(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.angle -= game->delta_time * PLR_ROTATE_VALUE;
    if (game->plr.angle < -360)
        game->plr.angle += 360;
}
