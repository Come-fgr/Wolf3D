/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** texture
*/

#ifndef TEXTURE_H_
    #define TEXTURE_H_

    #include <stddef.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>

typedef enum {
    B_QUIT,
    B_START,
    NB_TEXTURE
} texture_id_t;

typedef struct texture_s
{
    texture_id_t id;
    char *texture_path;
} texture_t;

    #include "button.h"

static const texture_t TEXTURE_LIST[NB_TEXTURE] = {
    {B_QUIT, QUIT_TEXTURE},
    {B_START, START_TEXTURE}
};

typedef struct component_sprite_s {
    texture_id_t id;
    sfTexture *texture;
    sfSprite *sprite;
} component_sprite_t;

#endif /* !TEXTURE_H_ */
