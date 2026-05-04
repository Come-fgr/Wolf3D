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
#include "graphics.h"

static void update_scene(game_t *game, scene_t scene_list[NB_SCENE],
    const scene_id_t scene_id)
{
    const component_t *component_list = scene_list[scene_id].component_list;

    for (entity_id_t index = 0; component_list[index].entity != NB_ENT; index++)
        ENTITY[component_list[index].entity].update(game,
            &component_list[index]);
}

static double update_frame_rate(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    double seconds = sfTime_asSeconds(time);

    sfClock_restart(clock);
    return 1 / seconds;
}

void update_game(game_t *game, scene_t scene_list[NB_SCENE])
{
    while (sfRenderWindow_pollEvent(game->window, game->event)) {
        if (game->event->type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window);
    }
    update_scene(game, scene_list, game->cur_scene);
    game->frame_sec = update_frame_rate(game->clock);
}
