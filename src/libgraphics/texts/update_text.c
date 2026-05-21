/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_text
*/

#include "graphics.h"
#include "config.h"

void update_text(game_t *game, const component_t *component)
{
    text_t *text = component->data;

    if (game == NULL || component == NULL
        || text->update_text == NULL)
        return;
    text->update_text(game, text->text);
}
