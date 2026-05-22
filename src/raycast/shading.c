/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** shading
*/

#include "castray.h"

static int shade_opacity(int alpha)
{
    if (alpha < 0)
        alpha = 0;
    if (alpha > 255)
        alpha = 255;
    return alpha;
}

sfColor shade_color(float corrected_dist, bool flash)
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
