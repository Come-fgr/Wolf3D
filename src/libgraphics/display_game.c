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

static void display_scene(sfRenderWindow *window, scene_t scene_list[NB_SCENE],
    scene_id_t scene_id)
{
    component_t **component_list = scene_list[scene_id].component_list;

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
        game->cur_scene);
    sfRenderWindow_display(game->window);
}
