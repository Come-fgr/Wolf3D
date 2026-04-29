/*
** EPITECH PROJECT, 2026
** Libgraphics
** File description:
** Base function for entity
*/

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Event.h>
#include "struct/game.h"

void display_sprite(sfRenderWindow *window, sfSprite *sprite,
    const component_t *component)
{
    sfSprite_setTextureRect(sprite, component->rect);
    sfSprite_setPosition(sprite, component->pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void destroy_component(component_t *component)
{
    free(component);
}
