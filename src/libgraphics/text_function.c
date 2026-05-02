/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** text_function
*/

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include "macro.h"
#include "graphics.h"

int init_text(component_t *component,
    component_ressource_t ressource_list[NB_RESSOURCE])
{
    text_t *data = component->data;
    sfText *text = sfText_create();

    if (text == NULL || data == NULL)
        return ERROR;
    sfText_setString(text, data->string);
    sfText_setFont(text, ressource_list[component->texture].font);
    sfText_setCharacterSize(text, data->size);
    data->text = text;
    return SUCCESS;
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
