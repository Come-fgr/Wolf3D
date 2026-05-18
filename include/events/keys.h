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
    sfKeyCode key;
    key_event_fnct_t fnct;
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

void go_to_menu_scene(game_t *game);

void player_rotate_right(game_t *game);
void player_rotate_left(game_t *game);
void player_rotate_stop(game_t *game);

void player_sprint_start(game_t *game);
void player_sprint_stop(game_t *game);

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
    { sfKeyQ, &player_move_left },
    { sfKeyD, &player_move_right },
    { sfKeyZ, &player_move_forward },
    { sfKeyS, &player_move_backward },
    { sfKeyA, &player_rotate_left },
    { sfKeyE, &player_rotate_right },
    { sfKeyEscape, &go_to_menu_scene },
    { sfKeyLShift, &player_sprint_start },
    { sfKeyUnknown, NULL }
};

/***
 * @brief Associates keys to functions to handle KeyPressed evt
 */
static const key_event_t key_released_evts[] = {
    { sfKeyQ, &player_move_stop_x },
    { sfKeyD, &player_move_stop_x },
    { sfKeyZ, &player_move_stop_y },
    { sfKeyS, &player_move_stop_y },
    { sfKeyA, &player_rotate_stop },
    { sfKeyE, &player_rotate_stop },
    { sfKeyLShift, &player_sprint_stop },
    { sfKeyUnknown, NULL }
};

#endif /* !EVENTS_KEYS_H_ */
