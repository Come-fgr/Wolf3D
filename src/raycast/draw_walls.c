/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** draw_walls
*/

#include "map.h"
#include "graphics.h"
#include "castray.h"

static void cache_wall_textures(game_t *game, sfTexture **types)
{
    types[0] = (sfTexture *)get_ressource("redbrick", game->ressource_list);
    types[1] = (sfTexture *)get_ressource("eagle", game->ressource_list);
}

static void compute_col(raycaster_t *disp, const player_t *player, int col)
{
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
    disp->top = (WINDOW_HEIGHT / 2.0f) - (disp->wall_height / 2.0f);
}

static void display_wall(sfRenderWindow *win, raycaster_t *disp,
    const player_t *player, int col)
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
    sfTexture *wall_types[NBR_WALL_TYPE];

    cache_wall_textures(game, wall_types);
    for (size_t col = 0; col < NUM_RAYS; ++col) {
        compute_col(disp, &game->plr, col);
        display_wall(game->window, disp, &game->plr, col);
    }
    free_struct(disp);
}
