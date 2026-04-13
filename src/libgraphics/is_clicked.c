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
#include "struct/entity.h"

sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component)
{
    return (evt->x > component->pos.x &&
        evt->x < component->pos.x + component->rect.width) &&
        (evt->y > component->pos.y &&
        evt->y < component->pos.y + component->rect.height);
}
