/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "struct/game.h"
    #include "graphics.h"

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8
    #define MAP_SCALE 4

void minimap(game_t *game);

static const int MAP[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 2, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 2, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

#endif /* !MAP_H_ */
