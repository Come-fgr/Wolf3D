/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include <stdio.h>
#include <math.h>

#include "struct/player.h"
#include "struct/game.h"

void update_player(player_t *plr, float delta_time)
{
    plr->pos.x += (cosf(plr->angle) * PLR_MOVE_VALUE * delta_time) * plr->vel.x;
    plr->pos.y += (sinf(plr->angle) * PLR_MOVE_VALUE * delta_time) * plr->vel.y;
}
