/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** draw_walls
*/

#include "map.h"
#include "graphics.h"
#include "castray.h"

static int shade_opacity(int alpha)
{
    if (alpha < 0)
        alpha = 0;
    if (alpha > 255)
        alpha = 255;
    return alpha;
}

static sfColor shade_color(float corrected_dist, bool flash)
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

static void display_wall(sfRenderWindow *win, raycaster_t *disp,
    player_t *player, int col)
{
    sfRectangleShape *wall = sfRectangleShape_create();
    sfColor shaded = {0};

    sfRectangleShape_setSize(wall, (sfVector2f){1.0f, disp->wall_height});
    sfRectangleShape_setPosition(wall, (sfVector2f){(float)col, disp->top});
    shaded = shade_color(disp->corrected, player->flash);
    sfRectangleShape_setFillColor(wall, shaded);
    sfRenderWindow_drawRectangleShape(win, wall, NULL);
    sfRectangleShape_destroy(wall);
}

void draw_walls(game_t *game)
{
    raycaster_t *disp = init_struct();
    sfRenderWindow *win = game->window;
    player_t *plr = &game->plr;

    for (int col = 0; col < NUM_RAYS; ++col) {
        disp->ray_angle = plr->angle - disp->half_fov
            + ((float)col + 0.5f) * disp->angle_step;
        disp->hitx = 0;
        disp->hity = 0;
        disp->wall_id = 0;
        disp->raw_dist = cast_single_ray(plr, disp);
        disp->corrected = disp->raw_dist
            * cosf(disp->ray_angle - plr->angle);
        if (disp->corrected <= 0)
            disp->corrected = 0.0001f;
        disp->wall_height = (TILE_SIZE * 277.0f) / disp->corrected;
        disp->top = (WINDOW_HEIGHT / 2.0f) - (disp->wall_height / 2.0f);
        display_wall(win, disp, plr, col);
    }
    free_struct(disp);
}
