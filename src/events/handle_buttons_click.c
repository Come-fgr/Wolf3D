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
    component_t **component_list = game ?
        game->scene_list[game->cur_scene].component_list : NULL;

    if (component_list == NULL || evt == NULL)
        return;
    for (size_t i = 0; component_list[i] != NULL; i++)
        if (is_clicked(&evt->mouseButton, component_list[i])
            && component_list[i]->data != NULL) {
            ((component_fn_t *)component_list[i]->data)(game);
            break;
        }
}
