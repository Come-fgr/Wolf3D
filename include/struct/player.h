/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <SFML/System/Vector2.h>
    #include <stdbool.h>

    // player.pos incrementing value per second
    #define PLR_MOVE_VALUE 150.0f

    // player.angle rotate value per second
    #define PLR_ROTATE_VALUE 2.5f

typedef struct player_s {
    sfVector2f pos;    // Player position
    sfVector2i vel;    // Player move velocity
    float angle;
    bool flash;
} player_t;

#endif /* !PLAYER_H_ */
