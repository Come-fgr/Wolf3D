/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** bs_world
*/

#include "bs_header.h"

static int shade_opacity(int alpha)
{
    if (alpha < 0)
        alpha = 0;
    if (alpha > 255)
        alpha = 255;
    return alpha;
}

static sfColor shade_color(sfColor *base, float corrected_dist, bool flash)
{
    int v = 0;

    if (corrected_dist > COLOR_MAX) {
        return (sfColor){0, 0, 0, 255};
    } else if (flash) {
        v = (int)(COLOR_MAX - corrected_dist + corrected_dist * 0.30f);
        v = shade_opacity(v);
        return (sfColor){(sfUint8)v, (sfUint8)v, (sfUint8)v, 255};
    } else {
        v = (int)(COLOR_MAX - corrected_dist);
        v = shade_opacity(v);
        return (sfColor){(sfUint8)v, (sfUint8)v, (sfUint8)v, 255};
    }
}

sfColor wall_color_for_id(int id)
{
    if (id == 1)
        return (sfColor){200, 120, 80, 255};
    if (id == 2)
        return (sfColor){100, 200, 140, 255};
    return (sfColor){170, 170, 170, 255};
}

int map_at(float x, float y)
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

void draw_world(sfRenderWindow *win)
{
    sfRectangleShape *rect = NULL;

    sfRenderWindow_clear(win, sfBlack);
    rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rect, (sfColor){80, 80, 120, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, WIN_HEIGHT / 2.0f});
    sfRectangleShape_setFillColor(rect, (sfColor){60, 140, 60, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void display_wall(sfRenderWindow *win, wolf_disp_t *disp,
    player_t *player, int col)
{
    sfRectangleShape *wall = sfRectangleShape_create();
    sfColor base = {0, 0, 0, 0};
    sfColor shaded = {0, 0, 0, 0};
    int texoff = 0;

    sfRectangleShape_setSize(wall, (sfVector2f){1.0f, disp->wall_height});
    sfRectangleShape_setPosition(wall, (sfVector2f){(float)col, disp->top});
    texoff = ((int)disp->hitx + (int)disp->hity) % TILE_SIZE;
    base = wall_color_for_id(disp->wall_id);
    shaded = shade_color(&base, disp->corrected, player->flash);
    sfRectangleShape_setFillColor(wall, shaded);
    sfRenderWindow_drawRectangleShape(win, wall, NULL);
    sfRectangleShape_destroy(wall);
}

void display_window(sfRenderWindow *win, player_t *player)
{
    wolf_disp_t *disp = init_struct();

    for (int col = 0; col < NUM_RAYS; ++col) {
        disp->ray_angle = player->angle - disp->half_fov
            + ((float)col + 0.5f) * disp->angle_step;
        disp->hitx = 0;
        disp->hity = 0;
        disp->wall_id = 0;
        disp->raw_dist = cast_single_ray(player, disp);
        disp->corrected = disp->raw_dist
            * cosf(disp->ray_angle - player->angle);
        if (disp->corrected <= 0)
            disp->corrected = 0.0001f;
        disp->wall_height = (TILE_SIZE * 277.0f) / disp->corrected;
        disp->top = (WIN_HEIGHT / 2.0f) - (disp->wall_height / 2.0f);
        display_wall(win, disp, player, col);
    }
    sfRenderWindow_display(win);
    free_struct(disp);
}
