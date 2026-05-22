/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** analyse_events
*/
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>

#include "events/events.h"
#include "struct/game.h"

static void trigger_associated_ev(sfEvent *evt, game_t *game)
{
    if (evt == NULL || game == NULL)
        return;
    for (size_t i = 0; evts_types[i].type != sfEvtCount; i++)
        if (evts_types[i].fnct && evts_types[i].type == evt->type)
            evts_types[i].fnct(evt, game);
}

sfEvent analyse_events(game_t *game)
{
    sfEvent evt = {0};

    if (game == NULL)
        return evt;
    while (sfRenderWindow_pollEvent(game->window, &evt)) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            game->run = false;
        }
        trigger_associated_ev(&evt, game);
    }
    return evt;
}
