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
    MENU_PAUSE,
    SETTINGS,
    NB_SCENE
} scene_id_t;

typedef struct scene_s {
    scene_id_t id;
    component_t **component_list;
    sfMusic *music;
} scene_t;

typedef struct scene_config_s {
    scene_id_t id;
    char *file;
    char *music;
} scene_config_t;

static const scene_config_t SCENES_CONFIG[NB_SCENE] = {
    {GAME, "config/game_scene.config", "BT-7274"},
    {MENU_START, "config/start_scene.config", NULL},
    {MENU_PAUSE, "config/pause_scene.config", NULL},
    {SETTINGS, "config/settings_scene.config", NULL}
};

#endif /* !SCENE_H */
