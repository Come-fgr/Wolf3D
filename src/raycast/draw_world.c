/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** world
*/

#include "graphics.h"
#include "castray.h"

void draw_world(game_t *game)
{
    sfRectangleShape *rect = NULL;
    sfRenderWindow *win = game->window;
    raycaster_t *disp = init_struct(game->settings.fov);

    rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){WIN_WIDTH, WIN_HEIGHT / 2.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rect, (sfColor){80, 80, 120, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, WIN_HEIGHT / 2.0f});
    sfRectangleShape_setFillColor(rect, (sfColor){60, 140, 60, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
    draw_walls(win, &game->plr, disp);
}
