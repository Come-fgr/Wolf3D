#include "bs_header.h"

sfColor wall_color_for_id(int id)
{
    if (id == 1) return (sfColor){200,120,80,255};
    if (id == 2) return (sfColor){100,200,140,255};
    return (sfColor){170,170,170,255};
}

int map_at(float x, float y)
{
    if (x < 0 || y < 0) return 0;
    int tx = (int) (x / TILE_SIZE);
    int ty = (int) (y / TILE_SIZE);
    if (tx < 0 || ty < 0 || tx >= MAP_W || ty >= MAP_H) return 0;
    return MAP[ty][tx];
}

/*
void minimap(sfRenderWindow *win)
{
    const int map_scale = 4;
    
    for (int y = 0; y < MAP_H; ++y) {
        for (int x = 0; x < MAP_W; ++x) {
            sfRectangleShape *b = sfRectangleShape_create();
            sfRectangleShape_setSize(b, (sfVector2f){TILE_SIZE/ map_scale - 1, TILE_SIZE / map_scale - 1});
            sfRectangleShape_setPosition(b, (sfVector2f){10 + x * (TILE_SIZE/map_scale), 10 + y * (TILE_SIZE/map_scale)});
            int id = MAP[y][x];
            if (id == 0) sfRectangleShape_setFillColor(b, (sfColor){30,30,30,200});
            else sfRectangleShape_setFillColor(b, wall_color_for_id(id));
            sfRenderWindow_drawRectangleShape(win, b, NULL);
            sfRectangleShape_destroy(b);
        }
    }
    sfCircleShape *player = sfCircleShape_create();
    sfCircleShape_setRadius(player, 4);
    sfCircleShape_setFillColor(player, sfRed);
    sfCircleShape_setPosition(player, (sfVector2f){10 + player.x / map_scale - 4, 10 + player.y / map_scale - 4});
    sfRenderWindow_drawCircleShape(win, player, NULL);
    sfCircleShape_destroy(player);
}
*/