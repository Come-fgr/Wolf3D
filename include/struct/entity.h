/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Entity struct
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>

typedef enum entity_id_s {
    B_QUIT,
    B_START,
    NB_ENT
} entity_id_t;

///

typedef struct component_s {
    entity_id_t id;
    sfVector2f pos;
    sfIntRect rect;
    void *data;
} component_t;

struct game_s;

typedef struct entity_s {
    entity_id_t id;
    char *texture_path;
    void (*update)(struct game_s *game, const component_t *component);
    void (*display)(sfRenderWindow *window, sfSprite *sprite,
        const component_t *component);
    void (*destroy)(component_t *component);
} entity_t;

typedef struct entity_sprite_s {
    entity_id_t id;
    char *texture_path;
    sfTexture *texture;
    sfSprite *sprite;
} entity_sprite_t;

#endif /* !ENTITY_H */
