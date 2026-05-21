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
#include <SFML/Graphics/RenderWindow.h>
#include "list.h"
#include "my_string.h"
#include "my.h"
#include "macro.h"
#include "graphics.h"
#include "config.h"
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

static void *get_button_funct(const char *function_name)
{
    for (size_t id = 0; id < NB_BUTTON; id++)
        if (my_strcmp(function_name, BUTTON_FUNCT[id].name) == SUCCESS)
            return BUTTON_FUNCT[id].funct;
    return NULL;
}

static long set_one_btn_variable(size_t *error, const char *str)
{
    char *endptr = NULL;
    long result = strtol(str, &endptr, STRLEN(DECA_BASE));

    *error += *endptr != '\0';
    return result;
}

static size_t set_button_variables(component_t *component, const char **config,
    list_t **ressource_list)
{
    size_t error = SUCCESS;

    component->entity = BUTTON;
    component->pos.x = set_one_btn_variable(&error, config[2]);
    component->pos.y = set_one_btn_variable(&error, config[3]);
    component->rect.width = set_one_btn_variable(&error, config[4]);
    component->rect.height = set_one_btn_variable(&error, config[5]);
    component->rect.left = 0;
    component->rect.top = 0;
    component->ressource = get_ressource(config[1], ressource_list);
    error += component->ressource == NULL;
    component->data = get_button_funct(config[1]);
    error += component->data == NULL;
    return error;
}

int init_button(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
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

//TODO: Set sprite in component->data
void display_button(sfRenderWindow *window, const component_t *component)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, (sfTexture *)component->ressource, sfTrue);
    sfSprite_setTextureRect(sprite, component->rect);
    sfSprite_setPosition(sprite, component->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void destroy_button(component_t *component)
{
    free(component);
}