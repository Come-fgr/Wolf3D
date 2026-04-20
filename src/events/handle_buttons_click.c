/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** ui_events
*/
#include <stdio.h>
#include "events/events.h"
#include "graphics.h"

void handle_buttons_click(sfEvent *evt, game_t *game)
{
    const component_t *component_list = game ?
        SCENES[game->cur_scene].component_list : NULL;

    if (component_list == NULL || evt == NULL)
        return;
    for (size_t i = 0; component_list[i].entity != NB_ENT; i++)
        if (is_clicked(&evt->mouseButton, &component_list[i])
            && component_list[i].triggered != NULL) {
            component_list[i].triggered(game);
            break;
        }
}
