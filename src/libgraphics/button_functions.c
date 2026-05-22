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

static button_t *create_button(const char **config, sfTexture *texture,
    sfVector2f *pos, sfFont *font)
{
    button_t *data = calloc(1, sizeof(button_t));
    size_t error = SUCCESS;

    if (data == NULL || texture == NULL) {
        free(data);
        return NULL;
    }
    data->rect.width = get_field_value(&error, config[BUTTON_RECT_WIDTH]);
    data->rect.height = get_field_value(&error, config[BUTTON_RECT_HEIGHT]);
    data->rect.left = 0;
    data->rect.top = 0;
    data->sprite = create_sprite(texture, &data->rect, pos);
    error += data->sprite == NULL;
    data->text = create_text(font, config[BUTTON_STRING],
        config[BUTTON_CHAR_SIZE], pos);
    error += data->text == NULL;
    center_text_on_sprite(data->text, data->sprite);
    data->button_funct = get_config_function(config[BUTTON_FUNCT]);
    error += data->button_funct == NULL;
    return error == SUCCESS ? data : NULL;
}

static size_t set_button_variables(component_t *component, const char **config,
    list_t **ressource_list)
{
    size_t error = SUCCESS;
    sfTexture *texture = get_ressource(config[BUTTON_TEXTURE], ressource_list);
    sfFont *font = get_ressource(config[BUTTON_FONT], ressource_list);

    component->entity = BUTTON;
    component->pos.x = get_field_value(&error, config[BUTTON_POS_X]);
    component->pos.y = get_field_value(&error, config[BUTTON_POS_Y]);
    component->data = create_button(config, texture, &component->pos, font);
    error += component->data == NULL;
    return error;
}

int init_button(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
{
    size_t error = SUCCESS;

    if (array_len(config) != BUTTON_NB_FIELDS) {
        if (flag_list[DEBUG])
            dprintf(STDERR_FILENO, "%sError: Wrong array size\n%s\n",
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

void update_button(game_t *game, const component_t *component)
{
    button_t *button = component->data;

    sfText_setColor(button->text, button->status == HOVER ? sfBlack : sfWhite);
    button->rect.left = button->rect.width * button->status;
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->status = is_hovered(game->window, component) ? HOVER : BASE;
}

void display_button(sfRenderWindow *window, const component_t *component)
{
    button_t *button = component->data;

    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}

void destroy_button(component_t *component)
{
    button_t *button = component->data;

    sfSprite_destroy(button->sprite);
    sfText_destroy(button->text);
    free(button);
    free(component);
}
