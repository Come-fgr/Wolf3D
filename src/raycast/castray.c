/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** castray
*/

#include "map.h"
#include "castray.h"

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

float cast_single_ray(const player_t *player, raycaster_t *disp, float angle,
    char **map)
{
    sfVector2f pos = player->pos;
    float past_x = pos.x;
    float dist = 0.0f;
    char cell = ' ';

    while (dist < 1024.0f + (player->flash ? FLASHLIGHT_DISTANCE : 0.0f)) {
        past_x = pos.x;
        pos.x += cosf(angle) * RAY_STEP;
        pos.y += sinf(angle) * RAY_STEP;
        dist += RAY_STEP;
        cell = map_at(pos.x, pos.y, map);
        if (cell != ' ') {
            display_set(disp, cell, pos.x, pos.y);
            check_side(disp, past_x, pos.x);
            return dist;
        }
    }
    display_set(disp, cell, pos.x, pos.y);
    disp->side = 0;
    return dist;
}
