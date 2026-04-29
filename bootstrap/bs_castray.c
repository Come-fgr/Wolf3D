#include "bs_header.h"

static float norm_angle(float a)
{
    const float TWO_PI = 2.0f * (float)M_PI;
    
    a = fmodf(a, TWO_PI);
    if (a < 0) a += TWO_PI;
    return a;
}

float cast_single_ray(const player_t *player, float ray_angle,
                             float *out_hitx, float *out_hity, int *out_wall)
{
    float a = norm_angle(ray_angle);
    float x = player->x, 
    float y = player->y;
    float dist = 0.0f;
    float maxd = 1024.0f + (player->flash ? FLASHLIGHT_DISTANCE : 0.0f);
    int cell = 0;

    while (dist < maxd) {
        x += cosf(a) * RAY_STEP;
        y += sinf(a) * RAY_STEP;
        dist += RAY_STEP;
        cell = map_at(x, y);
        if (cell != 0) {
            if (out_hitx) *out_hitx = x;
            if (out_hity) *out_hity = y;
            if (out_wall) *out_wall = cell;
            return dist;
        }
    }
    if (out_hitx) *out_hitx = x;
    if (out_hity) *out_hity = y;
    if (out_wall) *out_wall = 0;
    return dist;
}