/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Display the window
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include "graphics.h"

static void display_scene(sfRenderWindow *window,
    entity_sprite_t entity[NB_ENT], scene_id_t scene_id)
{
    const component_t *component_list = SCENES[scene_id].component_list;

    for (entity_id_t index = 0; component_list[index].id != NB_ENT; index++) {
        ENTITY[component_list[index].id].display(window,
            entity[component_list[index].id].sprite, &component_list[index]);
    }
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_scene(game->window, &game->entity, game->cur_scene);
    sfRenderWindow_display(game->window);
}
