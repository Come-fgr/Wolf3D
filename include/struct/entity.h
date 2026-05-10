/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Entity struct
*/

#ifndef ENTITY_H
    #define ENTITY_H

    #include "ressource.h"

typedef enum entity_id_s {
    BUTTON,
    TEXT,
    NB_ENT
} entity_id_t;

///

typedef struct component_s {
    entity_id_t entity;
    ressource_id_t texture;
    sfVector2f pos;
    sfIntRect rect;
    void *data;
} component_t;

struct game_s;

typedef int (entity_init_fn_t)(component_t *, component_ressource_t
    ressource_list[NB_RESSOURCE]);
typedef void (entity_update_fn_t)(struct game_s *, const component_t *);
typedef void (entity_display_fn_t)(sfRenderWindow *, sfSprite *,
    const component_t *);
typedef void (entity_destroy_fn_t)(component_t *);

typedef struct entity_s {
    entity_id_t id;
    char *name;
    entity_init_fn_t *init;
    entity_update_fn_t *update;
    entity_display_fn_t *display;
    entity_destroy_fn_t *destroy;
} entity_t;

#endif /* !ENTITY_H */
