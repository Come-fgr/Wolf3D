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
#include "macro.h"

static void update_scene(game_t *game, scene_t scene_list[NB_SCENE],
    const scene_id_t scene_id)
{
    component_t **component_list = scene_list
        ? scene_list[scene_id].component_list : NULL;

    if (game == NULL || component_list == NULL)
        return;
    for (entity_id_t index = 0; component_list[index] != NULL; index++)
        if (ENTITY[component_list[index]->entity].update != NULL)
            ENTITY[component_list[index]->entity].update(game,
                component_list[index]);
}

static float get_delta_time(sfClock *clock)
{
    sfTime time = clock ? sfClock_restart(clock) : (sfTime){0};

    if (clock == NULL)
        return ERROR;
    return sfTime_asSeconds(time);
}

void update_game(game_t *game)
{
    char **map = game ? get_ressource("level", game->ressource_list) : NULL;

    if (game == NULL || game->clock == NULL)
        return;
    game->delta_time = get_delta_time(game->clock);
    analyse_events(game);
    update_player(&game->plr, game->delta_time, map);
    update_scene(game, game->scene_list, game->cur_scene);
}
