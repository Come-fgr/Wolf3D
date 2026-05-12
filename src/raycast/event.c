/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** event
*/

#include "castray.h"

void events_game(sfRenderWindow *win, players_t *player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeyF))
            player->flash = !player->flash;
    }
}
