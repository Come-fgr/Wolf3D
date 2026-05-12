/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include "castray.h"

int main_game(void)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "Wolf3d", sfClose, NULL);
    players_t player = { 160.0f, 160.0f, (float)M_PI * 0.25f, false};

    if (!win)
        return 84;
    sfRenderWindow_setFramerateLimit(win, 60);
    while (sfRenderWindow_isOpen(win)) {
        events_game(win, &player);
        updating_player(&player);
        draw_world(win);
        display_window(win, &player);
    }
    sfRenderWindow_destroy(win);
    return 0;
}
