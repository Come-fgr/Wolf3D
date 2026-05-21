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

void start_game(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    game->cur_scene = GAME;
}

void exit_game(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    sfRenderWindow_close(game->window);
}

static size_t set_button_variables(component_t *component, const char **config,
    list_t **ressource_list)
{
    size_t error = SUCCESS;
    button_t *data = calloc(1, sizeof(button_t));
    sfTexture *texture = get_ressource(config[BUTTON_TEXTURE], ressource_list);

    if (data == NULL)
        return 1;
    error += texture == NULL;
    data->sprite = texture;
    component->entity = BUTTON;
    component->pos.x = get_field_value(&error, config[BUTTON_POS_X]);
    component->pos.y = get_field_value(&error, config[BUTTON_POS_Y]);
    data->rect.width = get_field_value(&error,
        config[BUTTON_RECT_WIDTH]);
    data->rect.height = get_field_value(&error,
        config[BUTTON_RECT_HEIGHT]);
    data->rect.left = 0;
    data->rect.top = 0;
    data->button_funct = get_config_function(config[BUTTON_FUNCT]);
    error += data->button_funct == NULL;
    component->data = data;
    return error;
}

int init_button(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
{
    size_t error = SUCCESS;

    if (array_len(config) != BUTTON_NB_FIELDS) {
        if (flag_list[DEBUG])
            dprintf(STDERR_FILENO, "%sError:\n\tWrong array size\n%s\n",
                RED, RESET);
        return ERROR;
    }
    error = set_button_variables(component, config, ressource_list);
    if (flag_list[DEBUG])
        printf("Load button \"%s\" = %s%s%s\n",
            config[BUTTON_FUNCT], error == SUCCESS ? GREEN : RED,
            error == SUCCESS ? "success" : "error", RESET);
    return error != SUCCESS ? ERROR : SUCCESS;
}

//TODO: Set sprite in component->data
void display_button(sfRenderWindow *window, const component_t *component)
{
    sfSprite *sprite = sfSprite_create();
    button_t *data = (button_t *)component->data;

    if (sprite == NULL)
        return;
    sfSprite_setTexture(sprite, data->sprite, sfTrue);
    sfSprite_setTextureRect(sprite, data->rect);
    sfSprite_setPosition(sprite, component->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void destroy_button(component_t *component)
{
    free(component);
}
