/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** world
*/

#include "graphics.h"
#include "castray.h"

static void draw_sky(sfRenderWindow *win)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect,
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT / 2.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rect, (sfColor){80, 80, 120, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static void draw_ground(sfRenderWindow *win)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect,
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT / 2.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, WINDOW_HEIGHT / 2.0f});
    sfRectangleShape_setFillColor(rect, (sfColor){60, 140, 60, 255});
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void draw_world(game_t *game)
{
    draw_sky(game->window);
    draw_ground(game->window);
    draw_walls(game);

}
