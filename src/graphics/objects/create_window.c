/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** create_window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include "graphics.h"

sfRenderWindow *create_window(bool fullscreen)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, fullscreen ? sfFullscreen :
        sfClose | sfResize, NULL);
    sfView *view = sfView_create();

    if (window == NULL || view == NULL)
        return NULL;
    sfView_setSize(view, (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfView_setCenter(view, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfRenderWindow_setView(window, view);
    sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
    sfView_destroy(view);
    return window;
}
