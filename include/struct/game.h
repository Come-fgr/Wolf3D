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
    #include <SFML/System/InputStream.h>

    #include "struct/scene.h"
    #include "struct/player.h"

    // Takes game struct pointer as argument
    #define GET_FPS(x) (1 / ((game_t *)(x))->delta_time)

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *clock;
    component_sprite_t sprite_list[NB_TEXTURE];
    scene_id_t cur_scene;
    player_t *plr;
    float delta_time;
    _Bool keys[sfKeyCount];
} game_t;

int init_game(game_t *game);
void update_game(game_t *game);
void display_game(game_t *game);
void destroy_game(game_t *game);

#endif /* !GAME_H */
