/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** text_function
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Font.h>

#include "macro.h"
#include "my.h"
#include "struct/ressource.h"
#include "graphics.h"
#include "config.h"

static size_t set_text_variables(component_t *component, const char **config,
    sfFont *font)
{
    size_t error = SUCCESS;
    text_t *data = calloc(1, sizeof(text_t));

    if (component == NULL || config == NULL || data == NULL)
        return FAIL;
    component->entity = TEXT;
    component->pos.x = get_field_value(&error, config[TEXT_POS_X]);
    component->pos.y = get_field_value(&error, config[TEXT_POS_Y]);
    data->text = create_text(font, config[TEXT_STRING], config[TEXT_CHAR_SIZE],
        &component->pos);
    error += data->text == NULL;
    data->update_text = get_config_function(config[TEXT_UPDATE_FN]);
    component->data = data;
    return error;
}

int init_text(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
{
    sfFont *font = config
        ? get_ressource(config[TEXT_FONT], ressource_list) : NULL;
    size_t error = SUCCESS;

    if (font == NULL || component == NULL || config == NULL
        || ressource_list == NULL || flag_list == NULL)
        return FAIL;
    if (array_len(config) != TEXT_NB_FIELDS || font == NULL) {
        if (flag_list[DEBUG])
            dprintf(STDERR_FILENO, "%sError:\n%s%s%s\n", RED,
                array_len(config) != TEXT_NB_FIELDS ? "\tWrong arr size\n" : "",
                font == NULL ? "\tFont is NULL\n" : "", RESET);
        return ERROR;
    }
    error = set_text_variables(component, config, font);
    if (flag_list[DEBUG])
        printf("Load text \"%s\" = %s%s%s\n",
            config[TEXT_STRING], error == SUCCESS ? GREEN : RED,
            error == SUCCESS ? "success" : "error", RESET);
    return error != SUCCESS ? ERROR : SUCCESS;
}

void display_text(sfRenderWindow *window, const component_t *component)
{
    if (window == NULL || component == NULL)
        return;
    sfRenderWindow_drawText(window, ((text_t *)component->data)->text, NULL);
}

void destroy_text(component_t *component)
{
    if (component == NULL)
        return;
    sfText_destroy(((text_t *)component->data)->text);
    free(component->data);
    free(component);
}
