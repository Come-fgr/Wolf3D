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

    #define WIN_WIDTH 800
    #define WIN_HEIGHT 600
    #define TILE_SIZE 64
    #define MAP_W 8
    #define MAP_H 8

    #define FOV (M_PI / 3.0f)
    #define NUM_RAYS WIN_WIDTH
    #define RAY_STEP 0.5f
    #define COLOR_MAX 225
    #define FLASHLIGHT_DISTANCE 500.0f

typedef struct player_s {
    float x, y;
    float angle;
    bool flash;
} player_t;

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

sfColor wall_color_for_id(int id);
int map_at(float x, float y);
float cast_single_ray(const player_t *player, float ray_angle,
                             float *out_hitx, float *out_hity, int *out_wall);

#endif //BS_HEADER_H_
