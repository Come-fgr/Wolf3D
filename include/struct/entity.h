/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Entity struct
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include "texture.h"

typedef enum entity_id_s {
    BUTTON,
    NB_ENT
} entity_id_t;

// Game struct
struct game_s;

typedef void (component_fn_t)(struct game_s *);

typedef struct component_s {
    entity_id_t entity;
    texture_id_t texture;
    sfVector2f pos;
    sfIntRect rect;
    component_fn_t *triggered;
} component_t;

// Events

typedef void (entity_click_fn_t)(struct game_s *);

// Basic entities functions

typedef void (entity_update_fn_t)(struct game_s *, const component_t *);
typedef void (entity_display_fn_t)(sfRenderWindow *, sfSprite *,
    const component_t *);
typedef void (entity_destroy_fn_t)(component_t *);

// Entities struct

typedef struct entity_s {
    entity_id_t id;
    entity_update_fn_t *update;     // Executed at each frame
    entity_display_fn_t *display;
    entity_destroy_fn_t *destroy;
    //entity_click_fn_t *onclick;     // Only GUI elements for now
} entity_t;

#endif /* !ENTITY_H */
