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

    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define TILE_SIZE 64
    #define MAP_W 8
    #define MAP_H 8

    #define FOV (M_PI / 3.0f)
    #define NUM_RAYS WIN_WIDTH
    #define RAY_STEP 0.5f
    #define COLOR_MAX 225
    #define FLASHLIGHT_DISTANCE 500.0f

typedef struct wolf_disp_s {
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
} wolf_disp_t;


typedef struct player_s {
    float x;
    float y;
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

void display_window(sfRenderWindow *win, player_t *player);
void draw_world(sfRenderWindow *win);
sfColor wall_color_for_id(int id);
wolf_disp_t *init_struct(void);
void free_struct(wolf_disp_t *disp_value);
int map_at(float x, float y);
float cast_single_ray(const player_t *player, wolf_disp_t *disp);

#endif //BS_HEADER_H_
