/*
** EPITECH PROJECT, 2026
** Libgraphics
** File description:
** button_function
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "SFML/Graphics/RenderWindow.h"
#include "my.h"
#include "macro.h"
#include "graphics.h"

void b_start(game_t *game, const component_t *component)
{
    if (game->event->type == sfEvtMouseButtonPressed &&
        is_clicked(&game->event->mouseButton, component))
        game->cur_scene = GAME;
}

void b_quit(game_t *game, const component_t *component)
{
    if (game->event->type == sfEvtMouseButtonPressed &&
        is_clicked(&game->event->mouseButton, component))
        sfRenderWindow_close(game->window);
}

void update_button(game_t *game, const component_t *component)
{
    ((entity_update_fn_t *)component->data)(game, component);
}

static ressource_id_t get_texture(char *texture_name)
{
    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++)
        if (my_strcmp(texture_name, RESSOURCE_LIST[id].name) == SUCCESS)
            return id;
    return NB_RESSOURCE;
}

int init_button(component_t *component, char **config, component_ressource_t
    ressource_list[NB_RESSOURCE])
{
    char *endptr = NULL;
    size_t error = SUCCESS;

    if (array_len(config) != 6)
        return ERROR;
    component->entity = BUTTON;
    component->pos.x = my_strtol(config[2], &endptr);
    error += *endptr != '\0';
    component->pos.y = my_strtol(config[3], &endptr);
    error += *endptr != '\0';
    component->rect.width = my_strtol(config[4], &endptr);
    error += *endptr != '\0';
    component->rect.height = my_strtol(config[5], &endptr);
    component->texture = get_texture(config[1]);
        error += component->texture != NB_RESSOURCE;
    return error != SUCCESS ? ERROR : SUCCESS;
}
