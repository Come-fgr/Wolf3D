/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Display the window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include "graphics.h"
#include "list.h"
#include "castray.h"

#include <stdio.h>

static void update_music(sfMusic **cur_music, sfMusic *scene_music,
    float volume)
{
    if (*cur_music != scene_music) {
        if (*cur_music != NULL)
            sfMusic_stop(*cur_music);
        *cur_music = scene_music;
    }
    if (*cur_music != NULL) {
        if (sfMusic_getStatus(*cur_music) != sfPlaying)
            sfMusic_play(*cur_music);
        sfMusic_setVolume(*cur_music, volume);
    }
}

static void display_scene(game_t *game)
{
    scene_t scene = game->scene_list[game->cur_scene];
    component_t **component_list = scene.component_list;

    update_music(&game->cur_music, scene.music, game->settings.music_volume);
    for (entity_id_t index = 0; component_list[index] != NULL; index++)
        ENTITY[component_list[index]->entity].display(game->window,
            component_list[index]);
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->cur_scene == GAME)
        draw_world(game);
    display_scene(game);
    sfRenderWindow_display(game->window);
}
