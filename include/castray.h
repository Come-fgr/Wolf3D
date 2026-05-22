/*
** EPITECH PROJECT, 2026
** header
** File description:
** None
*/

#ifndef BS_HEADER_H_
    #define BS_HEADER_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

    #include <math.h>
    #include <stdlib.h>

    #include "graphics.h"
    #include "struct/game.h"
    #include "struct/player.h"

    #define NUM_RAYS WINDOW_WIDTH
    #define RAY_STEP 0.1f
    #define COLOR_MAX 225
    #define FLASHLIGHT_DISTANCE 500.0f
    #define NBR_WALL_TYPE 2

typedef struct raycaster_s {
    sfTexture *wall_types[NBR_WALL_TYPE];
    unsigned char wall_id;
    int side;
    float half_fov;
    float angle_step;
    float ray_angle;
    float hitx;
    float hity;
    float raw_dist;
    float corrected;
    float wall_height;
    float top;
} raycaster_t;

void draw_walls(game_t *game);
void draw_world(game_t *game);
raycaster_t *init_struct(game_t *game);
float cast_single_ray(const player_t *player, raycaster_t *disp, float angle,
    char **map);
void free_struct(raycaster_t *disp_value);
sfColor shade_color(float corrected_dist, bool flash);

#endif //BS_HEADER_H_
