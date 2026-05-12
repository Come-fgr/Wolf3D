/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** text_function
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Font.h>
#include "macro.h"
#include "my.h"
#include "struct/ressource.h"
#include "graphics.h"

static sfFont *get_font(const char *texture_name, component_ressource_t
    ressource_list[NB_RESSOURCE])
{
    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++)
        if (my_strcmp(texture_name, ressource_list[id].name) == SUCCESS)
            return ressource_list[id].font;
    return NULL;
}

int init_text(component_t *component, const char **config, component_ressource_t
    ressource_list[NB_RESSOURCE])
{
    text_t *data = component->data;
    sfText *text = sfText_create();
    sfFont *font = get_font(config[1], ressource_list);
    char *endptr = NULL;
    size_t error = SUCCESS;

    if (array_len(config) != 6 || text == NULL || data == NULL || font == NULL)
        return ERROR;
    component->entity = TEXT;
    sfText_setString(text, config[4]);
    sfText_setFont(text, font);
    component->pos.x = my_strtol(config[2], &endptr);
    error += *endptr != '\0';
    component->pos.y = my_strtol(config[3], &endptr);
    error += *endptr != '\0';
    sfText_setCharacterSize(text, my_strtol(config[5], &endptr));
    error += *endptr != '\0';
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, component->pos);
    data->text = text;
    return error != SUCCESS ? ERROR : SUCCESS;
}

void display_text(sfRenderWindow *window, sfSprite *sprite,
    const component_t *component)
{
    (void)sprite;
    sfRenderWindow_drawText(window, ((text_t *)component->data)->text, NULL);
}

void destroy_text(component_t *component)
{
    sfText_destroy(((text_t *)component->data)->text);
}
