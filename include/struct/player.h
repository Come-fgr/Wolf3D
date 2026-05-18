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
    #define DEFAULT_PLR_SPEED 95.0f

    #define SPRINT_FACTOR 2

    // player.angle rotate value per second
    #define PLR_ROTATE_VALUE 2.5f

typedef struct player_s {
    sfVector2f pos;    // Player position
    sfVector2f vel;    // Player move velocity
    float rot_vel;    // Player rotation velocity
    float speed;
    float angle;
    bool flash;
} player_t;

#endif /* !PLAYER_H_ */
