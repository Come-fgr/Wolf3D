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

void update_player(player_t *plr, float delta)
{
    plr->angle += PLR_ROTATE_VALUE * plr->rot_vel * delta;
    plr->pos.x += (cosf(plr->angle) * plr->speed * delta) * plr->vel.y;
    plr->pos.y += (sinf(plr->angle) * plr->speed * delta) * plr->vel.y;
    if (plr->vel.x) {
        plr->pos.x += cosf(plr->angle - 90) * plr->speed * delta * plr->vel.x;
        plr->pos.y += sinf(plr->angle - 90) * plr->speed * delta * plr->vel.x;
    }
}
