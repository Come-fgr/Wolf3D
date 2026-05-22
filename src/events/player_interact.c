/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_move
*/

#include "map.h"
#include "struct/player.h"
#include "struct/game.h"

void player_interact(game_t *game, [[maybe_unused]] void *data)
{
    float dir_x = 0.0;
    float dir_y = 0.0;
    float hit_x = 0.0;
    float hit_y = 0.0;
    int tile_x = 0;
    int tile_y = 0;

    if (game == NULL)
        return;
    dir_x = cosf(game->plr.angle);
    dir_y = sinf(game->plr.angle);
    hit_x = game->plr.pos.x + dir_x * INTERACT_DIST;
    hit_y = game->plr.pos.y + dir_y * INTERACT_DIST;
    tile_x = (int)(hit_x / TILE_SIZE);
    tile_y = (int)(hit_y / TILE_SIZE);
    if (tile_x >= 0 && tile_y >= 0 &&
        tile_x < MAP_WIDTH && tile_y < MAP_HEIGHT) {
        if (MAP[tile_y][tile_x] == 2)
            MAP[tile_y][tile_x] = 0;
    }
}
