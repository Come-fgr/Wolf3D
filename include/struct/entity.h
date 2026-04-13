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

typedef void (entity_update_fn_t)(struct game_s *, const component_t *);
typedef void (entity_display_fn_t)(sfRenderWindow *, sfSprite *,
    const component_t *);
typedef void (entity_destroy_fn_t)(component_t *);

typedef struct entity_s {
    entity_id_t id;
    char *texture_path;
    entity_update_fn_t *update;
    entity_display_fn_t *display;
    entity_destroy_fn_t *destroy;
} entity_t;

typedef struct entity_sprite_s {
    entity_id_t id;
    char *texture_path;
    sfTexture *texture;
    sfSprite *sprite;
} entity_sprite_t;

#endif /* !ENTITY_H */
