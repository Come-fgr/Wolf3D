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
    component_sprite_t sprite_list[NB_TEXTURE];
    scene_id_t cur_scene;
    double frame_sec;
} game_t;

int init_game(game_t *game);
void update_game(game_t *game);
void display_game(game_t *game);
void destroy_game(game_t *game);

#endif /* !GAME_H */
