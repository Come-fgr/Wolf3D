/*
** EPITECH PROJECT, 2025
** My_hunter
** File description:
** Check if a component is clicked by the mouse
*/

#include <stdio.h>
#include <stddef.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include "struct/entity.h"

size_t is_clicked(const sfRenderWindow *window, const component_t *component)
{
    sfVector2i mouse = sfMouse_getPosition(window);

    return (mouse.x > component->pos.x &&
        mouse.x < component->pos.x + component->rect.width) &&
        (mouse.y > component->pos.y &&
        mouse.y < component->pos.y + component->rect.height);
}
