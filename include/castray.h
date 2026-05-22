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
    #include <stdio.h>
    #include <stdbool.h>

    #include "struct/game.h"
    #include "struct/player.h"

    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define TILE_SIZE 64
    #define MAP_W 8
    #define MAP_H 8

    #define NUM_RAYS WIN_WIDTH
    #define RAY_STEP 0.1f
    #define COLOR_MAX 225
    #define FLASHLIGHT_DISTANCE 500.0f

typedef struct raycaster_s {
    size_t wall_id;
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

static const int MAP[MAP_H][MAP_W] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 2, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 2, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

void draw_walls(sfRenderWindow *win, player_t *player, raycaster_t *disp);
void updating_player(player_t *player);
void draw_world(game_t *game);
raycaster_t *init_struct(float fov);
void free_struct(raycaster_t *disp_value);
float cast_single_ray(const player_t *player, raycaster_t *disp);

#endif //BS_HEADER_H_
