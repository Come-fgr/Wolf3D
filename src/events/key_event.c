/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** key_pressed
*/

#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdbool.h>

#include "events/keys.h"
#include "struct/game.h"
#include "my.h"

static void key_manage(
    sfEvent *evt, game_t *game, _Bool add_to_keys, const key_event_t arr[])
{
    game->keys[evt->key.code] = add_to_keys;
    for (int i = 0; arr && arr[i].key != sfKeyUnknown; i++) {
        if (evt->key.code == arr[i].key && arr[i].fnct) {
            arr[i].fnct(game);
        }
    }
}

void key_pressed(sfEvent *evt, game_t *game)
{
    return key_manage(evt, game, true, key_pressed_evts);
}

void key_released(sfEvent *evt, game_t *game)
{
    return key_manage(evt, game, false, key_released_evts);
}
