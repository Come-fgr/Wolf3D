/*
** EPITECH PROJECT, 2025
** My_hunter
** File description:
** Check if a component is clicked by the mouse
*/

#include <stdio.h>
#include <stddef.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include "graphics.h"

sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component)
{
    button_t *button = (button_t *)component->data;

    return (evt->x > component->pos.x &&
        evt->x < component->pos.x + button->rect.width) &&
        (evt->y > component->pos.y &&
        evt->y < component->pos.y + button->rect.height);
}
