/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** create_text
*/

#include <stdlib.h>
#include <SFML/Graphics/Text.h>

sfText *create_text(sfFont *font, const char *string, const char *char_size,
    sfVector2f *pos)
{
    char *endptr = NULL;
    sfText *text = sfText_create();

    if (text == NULL || font == NULL)
        return NULL;
    sfText_setCharacterSize(text, strtol(char_size, &endptr, 10));
    if (*endptr != '\0') {
        sfText_destroy(text);
        return NULL;
    }
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, *pos);
    return text;
}
