/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** create_sprite
*/

#include <stddef.h>
#include <SFML/Graphics/Sprite.h>

sfSprite *create_sprite(sfTexture *texture, sfIntRect *rect, sfVector2f *pos)
{
    sfSprite *sprite = sfSprite_create();

    if (sprite == NULL)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, *rect);
    sfSprite_setPosition(sprite, *pos);
    return sprite;
}
