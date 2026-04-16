/*
** EPITECH PROJECT, 2025
** game
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
////      Managing game fncts         ////
////////////////////////////////////////////

// Add functions prototypes here

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
    { sfKeyUnknown, NULL }
};

/***
 * @brief Associates keys to functions to handle KeyPressed evt
 */
static const key_event_t key_released_evts[] = {
    { sfKeyUnknown, NULL }
};

#endif /* !EVENTS_KEYS_H_ */
