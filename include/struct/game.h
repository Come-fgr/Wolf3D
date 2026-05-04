/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Game struct
*/

#ifndef GAME_H
    #define GAME_H

    #include <stddef.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window/Event.h>
    #include "struct/scene.h"

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent *event;
    sfClock *clock;
    component_ressource_t sprite_list[NB_RESSOURCE];
    scene_id_t cur_scene;
    double frame_sec;
} game_t;

int init_game(game_t *game, scene_t scene_list[NB_SCENE]);
void update_game(game_t *game, scene_t scene_list[NB_SCENE]);
void display_game(game_t *game, scene_t scene_list[NB_SCENE]);
void destroy_game(game_t *game);

#endif /* !GAME_H */
