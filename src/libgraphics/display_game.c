/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Display the window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include "graphics.h"
#include "castray.h"

static void display_scene(sfRenderWindow *window,
    component_ressource_t ressource_list[NB_ENT],
    scene_t scene_list[NB_SCENE], scene_id_t scene_id)
{
    component_t **component_list = scene_list[scene_id].component_list;

    for (entity_id_t index = 0; component_list[index] != NULL; index++)
        ENTITY[component_list[index]->entity].display(window,
            ressource_list[component_list[index]->texture].sprite,
            component_list[index]);
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->cur_scene == GAME)
        draw_world(game);
    display_scene(game->window, game->ressource_list, game->scene_list,
        game->cur_scene);
    sfRenderWindow_display(game->window);
}
