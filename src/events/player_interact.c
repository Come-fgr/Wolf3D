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
    sfVector2f dir = {0};
    sfVector2f hit = {0};
    sfVector2i tile_pos = {0};
    char **map = get_ressource("maze", game->ressource_list);

    if (game == NULL)
        return;
    dir.x = cosf(game->plr.angle);
    dir.y = sinf(game->plr.angle);
    hit.x = game->plr.pos.x + dir.x * INTERACT_DIST;
    hit.y = game->plr.pos.y + dir.y * INTERACT_DIST;
    tile_pos.x = (int)(hit.x / TILE_SIZE);
    tile_pos.y = (int)(hit.y / TILE_SIZE);
    if (tile_pos.x >= 0 && tile_pos.y >= 0 &&
        tile_pos.x < MAP_WIDTH && tile_pos.y < MAP_HEIGHT) {
        if (map[tile_pos.y][tile_pos.x] == 'B') {
            map[tile_pos.y][tile_pos.x] = ' ';
            game->score++;
        }
    }
}
