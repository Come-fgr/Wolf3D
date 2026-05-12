/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** bs_struct
*/

#include "bs_header.h"

wolf_disp_t *init_struct(void)
{
    wolf_disp_t *disp_value = malloc(sizeof(wolf_disp_t));

    disp_value->wall_id = 0;
    disp_value->half_fov = FOV / 2.0f;
    disp_value->angle_step = FOV / (float)NUM_RAYS;
    disp_value->ray_angle = 0.0;
    disp_value->hitx = 0.0;
    disp_value->hity = 0.0;
    disp_value->raw_dist = 0.0;
    disp_value->corrected = 0.0;
    disp_value->wall_height = 0.0;
    disp_value->top = 0.0;
    return disp_value;
}

void free_struct(wolf_disp_t *disp_value)
{
    free(disp_value);
}
