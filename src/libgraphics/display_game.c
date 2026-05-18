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
    component_sprite_t sprite_list[NB_ENT], scene_id_t scene_id)
{
    const component_t *component_list = SCENES[scene_id].component_list;

    for (size_t index = 0; component_list[index].entity != NB_ENT; index++)
        ENTITY[component_list[index].entity].display(window,
            sprite_list[component_list[index].texture].sprite,
            &component_list[index]);
}

void display_game(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->cur_scene == GAME)
        draw_world(game);
    display_scene(game->window, game->sprite_list, game->cur_scene);
    sfRenderWindow_display(game->window);
}
