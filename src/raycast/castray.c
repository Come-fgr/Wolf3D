/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** castray
*/

#include "map.h"
#include "castray.h"

static float norm_angle(float a)
{
    const float TWO_PI = 2.0f * (float)M_PI;

    a = fmodf(a, TWO_PI);
    if (a < 0)
        a += TWO_PI;
    return a;
}

static void display_set(raycaster_t *disp, char cell, float x, float y)
{
    disp->hitx = x;
    disp->hity = y;
    if (cell != ' ')
        disp->wall_id = cell == 'M' ? 1 : 2;
    else
        disp->wall_id = 0;
}

static char map_at(float x, float y, char **map)
{
    int tx = 0;
    int ty = 0;

    if (x < 0 || y < 0)
        return 0;
    tx = (int) (x / TILE_SIZE);
    ty = (int) (y / TILE_SIZE);
    if (tx < 0 || ty < 0 || tx >= MAP_WIDTH || ty >= MAP_HEIGHT)
        return ' ';
    return map[ty][tx];
}

static void check_side(raycaster_t *disp, float past_x, float x)
{
    int tilex_past = (int)(past_x / TILE_SIZE);
    int tilex_curr = (int)(x / TILE_SIZE);

    if (tilex_past != tilex_curr)
        disp->side = 0;
    else
        disp->side = 1;
}

float cast_single_ray(const player_t *player, raycaster_t *disp, char **map)
{
    float angle = norm_angle(disp->ray_angle);
    float x = player->pos.x;
    float y = player->pos.y;
    float past_x = x;
    float dist = 0.0f;
    float maxd = 1024.0f + (player->flash ? FLASHLIGHT_DISTANCE : 0.0f);
    char cell = ' ';

    while (dist < maxd) {
        past_x = x;
        x += cosf(angle) * RAY_STEP;
        y += sinf(angle) * RAY_STEP;
        dist += RAY_STEP;
        cell = map_at(x, y, map);
        if (cell != ' ') {
            display_set(disp, cell, x, y);
            check_side(disp, past_x, x);
            return dist;
        }
    }
    display_set(disp, cell, x, y);
    disp->side = 0;
    return dist;
}
