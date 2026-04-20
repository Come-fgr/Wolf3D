/*
** EPITECH PROJECT, 2025
** myradar
** File description:
** events_types
*/

#ifndef EVENTS_TYPES_H_
    #define EVENTS_TYPES_H_

    #include <SFML/Window/Event.h>
    #include <stddef.h>

    #include "events/keys.h"
    #include "struct/game.h"

////////////////////////////////////////////
////              Types                 ////
////////////////////////////////////////////

/***
 * @brief Function type to handle evt
 */
typedef void (*event_type_fnct_t)(sfEvent *, game_t *);

/***
 * @brief Event struct
 */
typedef struct event_type_e {
    sfEventType type;
    event_type_fnct_t fnct;
} event_type_t;

////////////////////////////////////////////
////            Functions               ////
////////////////////////////////////////////

void handle_buttons_click(sfEvent *evt, game_t *game);


/***
 * @brief Associates keys to functions to handle KeyPressed evt
 */
static const event_type_t evts_types[] = {
    { sfEvtKeyReleased, &key_released },
    { sfEvtKeyPressed, &key_pressed },
    { sfEvtMouseButtonPressed, &handle_buttons_click },
    { sfEvtCount, NULL }
};

/***
 * @brief Analyse user inputs
 *
 * @param window The render window
 * @param game Simulation game
 */
sfEvent analyse_events(sfRenderWindow *window, game_t *game);

#endif /* !EVENTS_TYPES_H_ */
