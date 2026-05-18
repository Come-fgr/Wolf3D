/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** castray
*/

#include "castray.h"

static float norm_angle(float a)
{
    const float TWO_PI = 2.0f * (float)M_PI;

    a = fmodf(a, TWO_PI);
    if (a < 0)
        a += TWO_PI;
    return a;
}

static void display_set(raycaster_t *disp, int cell, float x, float y)
{
    disp->hitx = x;
    disp->hity = y;
    if (cell != 0)
        disp->wall_id = cell;
    else
        disp->wall_id = 0;
}

static int map_at(float x, float y)
{
    int tx = 0;
    int ty = 0;

    if (x < 0 || y < 0)
        return 0;
    tx = (int) (x / TILE_SIZE);
    ty = (int) (y / TILE_SIZE);
    if (tx < 0 || ty < 0 || tx >= MAP_W || ty >= MAP_H)
        return 0;
    return MAP[ty][tx];
}

float cast_single_ray(const player_t *player, raycaster_t *disp)
{
    float angle = norm_angle(disp->ray_angle);
    float x = player->pos.x;
    float y = player->pos.y;
    float dist = 0.0f;
    float maxd = 1024.0f + (player->flash ? FLASHLIGHT_DISTANCE : 0.0f);
    int cell = 0;

    while (dist < maxd) {
        x += cosf(angle) * RAY_STEP;
        y += sinf(angle) * RAY_STEP;
        dist += RAY_STEP;
        cell = map_at(x, y);
        if (cell != 0) {
            display_set(disp, cell, x, y);
            return dist;
        }
    }
    display_set(disp, cell, x, y);
    return dist;
}
