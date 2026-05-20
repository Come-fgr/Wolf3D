/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Scene struct
*/

#ifndef SCENE_H
    #define SCENE_H

    #include "struct/entity.h"

typedef enum scene_id_e {
    GAME,
    MENU_START,
//    MENU_PAUSE,
    NB_SCENE
} scene_id_t;

///

typedef struct scene_s {
    scene_id_t id;
    component_t **component_list;
} scene_t;

#endif /* !SCENE_H */
