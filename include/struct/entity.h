/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Entity struct
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include "my.h"
    #include "ressource.h"

typedef enum properties_e {
    CLICKABLE,
    NO_PROPERTIES,
    NB_PROPERTIES
} properties_t;

typedef enum entity_id_e {
    BUTTON,
    TEXT,
    NB_ENT
} entity_id_t;

// Game struct
struct game_s;

typedef void (component_fn_t)(struct game_s *);

typedef struct component_s {
    entity_id_t entity;
    ressource_id_t texture;
    sfVector2f pos;
    sfIntRect rect;
    void *data;
} component_t;

// Events

typedef void (entity_click_fn_t)(struct game_s *);

// Basic entities functions

typedef int (entity_init_fn_t)(component_t *, const char **,
    component_ressource_t [NB_RESSOURCE], bool [NB_FLAGS]);
typedef void (entity_update_fn_t)(struct game_s *, const component_t *);
typedef void (entity_display_fn_t)(sfRenderWindow *, sfSprite *,
    const component_t *);
typedef void (entity_destroy_fn_t)(component_t *);

// Entities struct

typedef struct entity_s {
    entity_id_t id;
    char *name;
    entity_init_fn_t *init;
    entity_update_fn_t *update;     // Executed at each frame
    entity_display_fn_t *display;
    entity_destroy_fn_t *destroy;
    properties_t props;
} entity_t;

#endif /* !ENTITY_H */
