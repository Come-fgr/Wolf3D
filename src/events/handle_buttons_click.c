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
    button_t *button = NULL;

    if (component_list == NULL || evt == NULL)
        return;
    for (size_t i = 0; component_list[i] != NULL; i++) {
        if (ENTITY[component_list[i]->entity].props == CLICKABLE)
            button = (button_t *)component_list[i]->data;
        if (button != NULL &&
            (button->status == HOVER || button->status == CLICK)) {
            button->status = CLICK;
            button->button_funct(game);
            break;
        }
    }
}
