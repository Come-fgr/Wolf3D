/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** myevents
*/

#ifndef EVENTS_KEYS_H_
    #define EVENTS_KEYS_H_

    #include <SFML/Window/Event.h>
    #include <stddef.h>

    #include "struct/game.h"

////////////////////////////////////////////
////              Types                 ////
////////////////////////////////////////////

/***
 * @brief Function type to handle key pressed evt
 */
typedef void (*key_event_fnct_t)(game_t *);

/***
 * @brief Key pressed event struct
 */
typedef struct key_event_e {
    key_event_fnct_t fnct;
    sfKeyCode keys[sfKeyCount];
} key_event_t;

////////////////////////////////////////////
////      Managing game fncts           ////
////////////////////////////////////////////

void player_move_left(game_t *game);
void player_move_right(game_t *game);
void player_move_forward(game_t *game);
void player_move_backward(game_t *game);

void player_move_stop_x(game_t *game);
void player_move_stop_y(game_t *game);

void go_to_pause_scene(game_t *game);

void player_rotate_right(game_t *game);
void player_rotate_left(game_t *game);
void player_rotate_stop(game_t *game);

void player_sprint_start(game_t *game);
void player_sprint_stop(game_t *game);

void player_flashlight_toggle(game_t *game);

////////////////////////////////////////////
////   Handler of KeyPressed Event
////////////////////////////////////////////

/***
 * @brief Key pressed event handler
 *
 * @param evt The keyPressed evt
 * @param game Simulation game
 */
void key_pressed(sfEvent *evt, game_t *game);

/***
 * @brief Key released event handler
 *
 * @param evt The keyPressed evt
 * @param game Simulation game
 */
void key_released(sfEvent *evt, game_t *game);

/***
 * @brief Associates keys to functions to handle KeyReleased evt
 */
static const key_event_t key_pressed_evts[] = {
    { &player_move_left, {sfKeyQ, sfKeyUnknown} },
    { &player_move_right, {sfKeyD, sfKeyUnknown} },
    { &player_move_forward, {sfKeyZ, sfKeyUnknown} },
    { &player_move_backward, {sfKeyS, sfKeyUnknown} },
    { &player_rotate_left, {sfKeyA, sfKeyUnknown} },
    { &player_rotate_right, {sfKeyE, sfKeyUnknown} },
    { &go_to_pause_scene, {sfKeyEscape, sfKeyUnknown} },
    { &player_sprint_start, {sfKeyLShift, sfKeyUnknown} },
    { &player_flashlight_toggle, {sfKeyF, sfKeyUnknown} },
    { NULL, {sfKeyUnknown} }
};

/***
 * @brief Associates keys to functions to handle KeyPressed evt
 */
static const key_event_t key_released_evts[] = {
    { &player_move_stop_x, {sfKeyQ, sfKeyD, sfKeyUnknown} },
    { &player_move_stop_y, {sfKeyZ, sfKeyS, sfKeyUnknown} },
    { &player_rotate_stop, {sfKeyA, sfKeyE, sfKeyUnknown} },
    { &player_sprint_stop, {sfKeyLShift, sfKeyUnknown} },
    { NULL, {sfKeyUnknown} }
};

typedef enum key_flag_e {
    KEY_ADD = 1,            // Add to game.keys
    KEY_ALL_REQUIRED = 2
} key_flag_t;

#endif /* !EVENTS_KEYS_H_ */
