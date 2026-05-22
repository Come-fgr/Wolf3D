/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** struct_manip
*/

#include "castray.h"

static void cache_wall_textures(game_t *game, sfTexture **types)
{
    if (game == NULL || types == NULL)
        return;
    types[0] = (sfTexture *)get_ressource("redbrick", game->ressource_list);
    types[1] = (sfTexture *)get_ressource("eagle", game->ressource_list);
}

raycaster_t *init_struct(game_t *game)
{
    raycaster_t *disp_value = calloc(1, sizeof(raycaster_t));

    if (disp_value == NULL || game == NULL) {
        free(disp_value);
        return NULL;
    }
    cache_wall_textures(game, disp_value->wall_types);
    disp_value->wall_id = 0;
    disp_value->side = 0;
    disp_value->half_fov = DEG_TO_RAD(game->settings.fov) / 2.0f;
    disp_value->angle_step = DEG_TO_RAD(game->settings.fov) / (float)NUM_RAYS;
    disp_value->ray_angle = 0.0;
    disp_value->hitx = 0.0;
    disp_value->hity = 0.0;
    disp_value->raw_dist = 0.0;
    disp_value->corrected = 0.0;
    disp_value->wall_height = 0.0;
    disp_value->top = 0.0;
    return disp_value;
}
