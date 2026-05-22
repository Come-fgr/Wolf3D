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
    #include <SFML/Audio/Music.h>
    #include "struct/scene.h"
    #include "struct/player.h"
    #include "struct/settings.h"
    #include "list.h"
    #include "my.h"

    // Takes game struct pointer as argument
    #define GET_FPS(x) ((size_t)(1 / ((game_t *)(x))->delta_time))

typedef struct game_s {
    bool run;
    sfRenderWindow *window;
    sfClock *clock;
    list_t **ressource_list;
    scene_t scene_list[NB_SCENE];
    scene_id_t cur_scene;
    scene_id_t prev_scene;
    player_t plr;
    float delta_time;
    size_t score;
    bool keys[sfKeyCount];
    bool debug_mode;
    sfMusic *cur_music;
    settings_t settings;
} game_t;

int init_game(game_t *game, bool flag_list[NB_FLAGS]);
void update_game(game_t *game);
void display_game(game_t *game);
void destroy_game(game_t *game);

#endif /* !GAME_H */
