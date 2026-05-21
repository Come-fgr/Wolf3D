/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** center_text_on_sprite
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>

void center_text_on_sprite(sfText *text, const sfSprite *sprite)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
    sfFloatRect text_rect = sfText_getLocalBounds(text);
    float sprite_x = sprite_rect.left + sprite_rect.width / 2;
    float sprite_y = sprite_rect.top + sprite_rect.height / 2;

    sfText_setPosition(text, (sfVector2f){
            sprite_x - (text_rect.width / 2 + text_rect.left),
            sprite_y - (text_rect.height / 2 + text_rect.top)
    });
}
