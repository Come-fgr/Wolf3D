/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Update windows and handle events for game
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Keyboard.h>

#include "events/events.h"
#include "graphics.h"

static void update_scene(game_t *game, const scene_id_t scene_id)
{
    const component_t *component_list = SCENES[scene_id].component_list;

    for (size_t index = 0; component_list[index].entity != NB_ENT; index++)
        if (ENTITY[component_list[index].entity].update != NULL)
            ENTITY[component_list[index].entity].update(
                game, &component_list[index]);
}

static float get_delta_time(sfClock *clock)
{
    sfTime time = sfClock_restart(clock);

    return sfTime_asSeconds(time);
}

void update_game(game_t *game)
{
    analyse_events(game);
    update_player(game);
    update_scene(game, game->cur_scene);
    game->delta_time = get_delta_time(game->clock);
}
