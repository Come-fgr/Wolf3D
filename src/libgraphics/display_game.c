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

static void update_music(sfMusic *cur_music, sfMusic *scene_music)
{
    if (cur_music != scene_music) {
        if (cur_music != NULL) {
            sfMusic_stop(cur_music);
            printf("Music stopped\n");
        }
        cur_music = scene_music;
    }
    if (cur_music != NULL)
        if (sfMusic_getStatus(cur_music) != sfPlaying)
            sfMusic_play(cur_music);
}

static void display_scene(sfRenderWindow *window, scene_t scene_list[NB_SCENE],
    scene_id_t scene_id, sfMusic *cur_music)
{
    component_t **component_list = scene_list[scene_id].component_list;

    update_music(cur_music, scene_list[scene_id].music);
    for (entity_id_t index = 0; component_list[index] != NULL; index++)
        ENTITY[component_list[index]->entity].display(window,
            component_list[index]);
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->cur_scene == GAME)
        draw_world(game);
    display_scene(game->window, game->scene_list,
        game->cur_scene, game->cur_music);
    sfRenderWindow_display(game->window);
}
