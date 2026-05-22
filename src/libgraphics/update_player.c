/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include <stdio.h>
#include <math.h>

#include "map.h"
#include "castray.h"
#include "events/keys.h"
#include "struct/player.h"
#include "struct/game.h"

static void update_stamina(player_t *plr, float delta)
{
    if (plr == NULL)
        return;
    plr->stamina += plr->running
        ? -STAMINA_RUN_COST * delta : STAMINA_REGEN * delta;
    if (plr->stamina <= 0) {
        plr->stamina = 0;
        plr->speed = DEFAULT_PLR_SPEED;
        plr->running = false;
    } else if (plr->stamina > PLR_MAX_STAMINA)
        plr->stamina = PLR_MAX_STAMINA;
}

static bool is_walkable(float x, float y)
{
    int tile_x = 0;
    int tile_y = 0;

    if (x < 0.0f || y < 0.0f)
        return false;
    tile_x = (int)(x / TILE_SIZE);
    tile_y = (int)(y / TILE_SIZE);
    if (tile_x < 0 || tile_y < 0 ||
        tile_x >= MAP_WIDTH || tile_y >= MAP_HEIGHT)
        return false;
    return MAP[tile_y][tile_x] == 0;
}

static bool can_move_to(float x, float y)
{
    float collision_radius = 6.0f;

    return is_walkable(x - collision_radius, y - collision_radius)
        && is_walkable(x + collision_radius, y - collision_radius)
        && is_walkable(x - collision_radius, y + collision_radius)
        && is_walkable(x + collision_radius, y + collision_radius);
}

static void apply_move(player_t *plr, float dx, float dy)
{
    float next_x = plr ? plr->pos.x + dx : 0;
    float next_y = plr ? plr->pos.y + dy : 0;

    if (plr == NULL)
        return;
    if (can_move_to(next_x, plr->pos.y))
        plr->pos.x = next_x;
    if (can_move_to(plr->pos.x, next_y))
        plr->pos.y = next_y;
}

void update_player(player_t *plr, float delta)
{
    float updown_dx = 0.0;
    float updown_dy = 0.0;
    float leftright_dx = 0.0;
    float leftright_dy = 0.0;

    if (plr == NULL)
        return;
    update_stamina(plr, delta);
    plr->angle += PLR_ROTATE_VALUE * plr->rot_vel * delta;
    updown_dx = cosf(plr->angle) * plr->speed * delta * plr->vel.y;
    updown_dy = sinf(plr->angle) * plr->speed * delta * plr->vel.y;
    leftright_dx = cosf(plr->angle - (M_PI / 2)) * plr->speed
        * delta * plr->vel.x;
    leftright_dy = sinf(plr->angle - (M_PI / 2)) * plr->speed
        * delta * plr->vel.x;
    apply_move(plr, updown_dx + leftright_dx, updown_dy + leftright_dy);
}
