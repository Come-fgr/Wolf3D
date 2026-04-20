/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include <stdio.h>
#include "struct/player.h"
#include "struct/game.h"

void update_player(game_t *game)
{
    game->plr->pos.x += game->plr->vel.x * PLR_MOVE_VALUE;
    game->plr->pos.y += game->plr->vel.y * PLR_MOVE_VALUE;
}
