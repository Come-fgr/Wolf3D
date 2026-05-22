/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** draw_walls
*/

#include <stdio.h>
#include "map.h"
#include "graphics.h"
#include "castray.h"

static float norm_angle(float a)
{
    const float TWO_PI = 2.0f * (float)M_PI;

    a = fmodf(a, TWO_PI);
    if (a < 0)
        a += TWO_PI;
    return a;
}

static void compute_col(raycaster_t *disp, const player_t *player, int col)
{
    disp->ray_angle = player->angle - disp->half_fov
        + ((float)col + 0.5f) * disp->angle_step;
    disp->hitx = 0;
    disp->hity = 0;
    disp->wall_id = 0;
    disp->raw_dist = cast_single_ray(player, disp, norm_angle(disp->ray_angle));
    disp->corrected = disp->raw_dist
        * cosf(disp->ray_angle - player->angle);
    if (disp->corrected <= 0)
        disp->corrected = 0.0001f;
    disp->wall_height = (TILE_SIZE * 277.0f) / disp->corrected;
    disp->top = (WINDOW_HEIGHT / 2.0f) - (disp->wall_height / 2.0f);
}

static int compute_tex_x(raycaster_t *disp, int tex_width)
{
    float wall_x = 0.0;
    int tex_x = 0;

    if (disp->side == 0)
        wall_x = fmodf(disp->hity, (float)TILE_SIZE);
    else
        wall_x = fmodf(disp->hitx, (float)TILE_SIZE);
    if (wall_x < 0.0f)
        wall_x += TILE_SIZE;
    tex_x = (int)((wall_x / (float)TILE_SIZE) * (float)tex_width);
    if ((disp->side == 0 && cosf(disp->ray_angle) > 0.0f)
        || (disp->side == 1 && sinf(disp->ray_angle) < 0.0f))
        tex_x = tex_width - tex_x - 1;
    return tex_x >= tex_width ? tex_width : tex_x;
}

static void display_wall(game_t *game, raycaster_t *disp, int col,
    sfRectangleShape *wall)
{
    sfTexture *tex = disp && disp->wall_id
        ? disp->wall_types[disp->wall_id - 1] : NULL;
    sfVector2u tex_size = tex ? sfTexture_getSize(tex) : (sfVector2u){0, 0};
    sfIntRect tex_rect = {0};
    sfColor shaded = {0};

    if (tex == NULL)
        return;
    tex_rect = (sfIntRect){(int)compute_tex_x(disp, tex_size.x),
        0, 1, (int)tex_size.y};
    sfRectangleShape_setTexture(wall, tex, sfTrue);
    sfRectangleShape_setTextureRect(wall, tex_rect);
    sfRectangleShape_setSize(wall, (sfVector2f){1.0f, disp->wall_height});
    sfRectangleShape_setPosition(wall, (sfVector2f){(float)col, disp->top});
    shaded = shade_color(disp->corrected, game->plr.flash);
    sfRectangleShape_setFillColor(wall, shaded);
    sfRenderWindow_drawRectangleShape(game->window, wall, NULL);
}

void draw_walls(game_t *game)
{
    raycaster_t *disp = init_struct(game);
    sfRectangleShape *wall = sfRectangleShape_create();

    for (size_t col = 0; disp && wall && col < NUM_RAYS; ++col) {
        compute_col(disp, &game->plr, col);
        display_wall(game, disp, col, wall);
    }
    sfRectangleShape_destroy(wall);
    free(disp);
}
