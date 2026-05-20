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
#include "castray.h"

void b_start(game_t *game)
{
    if (game == NULL)
        return;
    game->cur_scene = GAME;
}

void b_quit(game_t *game)
{
    if (game == NULL)
        return;
    sfRenderWindow_close(game->window);
}

static ressource_id_t get_texture(const char *texture_name)
{
    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++)
        if (my_strcmp(texture_name, RESSOURCE_LIST[id].name) == SUCCESS)
            return id;
    return NB_RESSOURCE;
}

static void *get_button_funct(const char *function_name)
{
    for (size_t id = 0; id < NB_BUTTON; id++)
        if (my_strcmp(function_name, BUTTON_FUNCT[id].name) == SUCCESS)
            return BUTTON_FUNCT[id].funct;
    return NULL;
}

static size_t set_button_variables(component_t *component, const char **config,
    component_ressource_t ressource_list[NB_RESSOURCE])
{
    char *endptr = NULL;
    size_t error = SUCCESS;

    component->entity = BUTTON;
    component->pos.x = my_strtol(config[2], &endptr);
    error += *endptr != '\0';
    component->pos.y = my_strtol(config[3], &endptr);
    error += *endptr != '\0';
    component->rect.width = my_strtol(config[4], &endptr);
    error += *endptr != '\0';
    component->rect.height = my_strtol(config[5], &endptr);
    error += *endptr != '\0';
    component->rect.left = 0;
    component->rect.top = 0;
    component->texture = get_texture(config[1]);
    error += component->texture == NB_RESSOURCE;
    component->data = get_button_funct(config[1]);
    error += component->data == NULL;
    return error;
}

int init_button(component_t *component, const char **config,
    component_ressource_t ressource_list[NB_RESSOURCE],
    bool flag_list[NB_FLAGS])
{
    size_t error = SUCCESS;

    if (array_len(config) != 6) {
        if (flag_list[DEBUG])
            minidprintf(STDERR_FILENO, "%sError:\n\tWrong array size\n%s\n",
                RED, RESET);
        return ERROR;
    }
    error = set_button_variables(component, config, ressource_list);
    if (flag_list[DEBUG])
        minidprintf(STDOUT_FILENO, "Load button \"%s\" = %s%s%s\n",
            config[1], error == SUCCESS ? GREEN : RED,
            error == SUCCESS ? "success" : "error", RESET);
    return error != SUCCESS ? ERROR : SUCCESS;
}
