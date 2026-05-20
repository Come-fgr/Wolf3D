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

static bool is_a_key_pressed(const sfKeyCode arr[])
{
    for (size_t i = 0; arr && arr[i] != sfKeyUnknown; i++)
        if (sfKeyboard_isKeyPressed(arr[i]))
            return true;
    return false;
}

static bool key_in_arr(sfKeyCode key, const sfKeyCode arr[])
{
    for (size_t i = 0; arr && arr[i] != sfKeyUnknown; i++)
        if (arr[i] == key)
            return true;
    return false;
}

static void key_manage_key_row(
    sfEvent *evt, game_t *game, key_flag_t flags, const key_event_t arr[])
{
    if (!key_in_arr(evt->key.code, arr->keys)
        || (flags & KEY_ALL_REQUIRED && is_a_key_pressed(arr->keys)))
        return;
    if (arr->fnct)
        arr->fnct(game);
}

static void key_manage(
    sfEvent *evt, game_t *game, key_flag_t flags, const key_event_t arr[])
{
    if (evt == NULL || game == NULL || arr == NULL)
        return;
    game->keys[evt->key.code] = flags & KEY_ADD;
    for (size_t i = 0; arr && arr[i].keys[0] != sfKeyUnknown; i++)
        key_manage_key_row(evt, game, flags, &arr[i]);
}

void key_pressed(sfEvent *evt, game_t *game)
{
    return key_manage(evt, game, KEY_ADD, key_pressed_evts);
}

void key_released(sfEvent *evt, game_t *game)
{
    return key_manage(evt, game, KEY_ALL_REQUIRED, key_released_evts);
}
