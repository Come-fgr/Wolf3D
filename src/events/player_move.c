/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_move
*/

#include "struct/game.h"

void player_move_left(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.x = 1.0f;
}

void player_move_right(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.x = -1.0f;
}

void player_move_forward(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.y = 1.0f;
}

void player_move_backward(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.vel.y = -1.0f;
}
