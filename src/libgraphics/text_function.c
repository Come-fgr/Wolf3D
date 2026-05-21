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
    sfFont *font, text_t *data)
{
    sfText *text = sfText_create();
    char *endptr = NULL;
    size_t error = SUCCESS;

    if (text == NULL)
        return ERROR;
    component->entity = TEXT;
    sfText_setString(text, config[TEXT_STRING]);
    sfText_setFont(text, font);
    component->pos.x = get_field_value(&error, config[TEXT_POS_X]);
    component->pos.y = get_field_value(&error, config[TEXT_POS_Y]);
    sfText_setCharacterSize(text, strtol(config[TEXT_CHAR_SIZE], &endptr, 10));
    error += *endptr != '\0';
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, component->pos);
    data->text = text;
    component->data = data;
    return error;
}

int init_text(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
{
    text_t *data = calloc(1, sizeof(text_t));
    sfFont *font = get_ressource(config[TEXT_FONT], ressource_list);
    size_t error = SUCCESS;

    if (array_len(config) != TEXT_CONFIG || font == NULL || data == NULL) {
        if (flag_list[DEBUG])
            dprintf(STDERR_FILENO, "%sError:\n%s%s%s\n", RED,
                array_len(config) != 6 ? "\tWrong array size\n" : "",
                font == NULL ? "\tFont is NULL\n" : "", RESET);
        return ERROR;
    }
    error = set_text_variables(component, config, font, data);
    if (flag_list[DEBUG])
        printf("Load text \"%s\" = %s%s%s\n",
            config[4], error == SUCCESS ? GREEN : RED,
            error == SUCCESS ? "success" : "error", RESET);
    return error != SUCCESS ? ERROR : SUCCESS;
}

void display_text(sfRenderWindow *window, const component_t *component)
{
    sfRenderWindow_drawText(window, ((text_t *)component->data)->text, NULL);
}

void destroy_text(component_t *component)
{
    sfText_destroy(((text_t *)component->data)->text);
}
