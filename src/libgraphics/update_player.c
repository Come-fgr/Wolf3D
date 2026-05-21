/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include <stdio.h>
#include <math.h>

#include "events/keys.h"
#include "struct/player.h"
#include "struct/game.h"

static void update_stamina(player_t *plr, float delta)
{
    printf("%f\n", plr->stamina);
    plr->stamina += plr->running
        ? -STAMINA_RUN_COST * delta : STAMINA_REGEN * delta;
    if (plr->stamina <= 0) {
        plr->stamina = 0;
        plr->speed = DEFAULT_PLR_SPEED;
        plr->running = false;
    } else if (plr->stamina > PLR_MAX_STAMINA)
        plr->stamina = PLR_MAX_STAMINA;
}

void update_player(player_t *plr, float delta)
{
    update_stamina(plr, delta);
    plr->angle += PLR_ROTATE_VALUE * plr->rot_vel * delta;
    plr->pos.x += cosf(plr->angle) * plr->speed * delta * plr->vel.y;
    plr->pos.y += sinf(plr->angle) * plr->speed * delta * plr->vel.y;
    plr->pos.x += cosf(plr->angle - 90) * plr->speed * delta * plr->vel.x;
    plr->pos.y += sinf(plr->angle - 90) * plr->speed * delta * plr->vel.x;
}
