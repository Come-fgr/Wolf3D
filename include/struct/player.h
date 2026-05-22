/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <stdbool.h>

    #define DEFAULT_PLAYER_POS_X 160.0f
    #define DEFAULT_PLAYER_POS_Y 160.0f
    #define DEFAULT_PLAYER_ANGLE (M_PI * 0.25f)

    // player.pos incrementing value per second
    #define DEFAULT_PLR_SPEED 150.0f

    #define SPRINT_FACTOR 2

    // player.angle rotate value per second
    #define PLR_ROTATE_VALUE 2.5f

    #define PLR_MAX_LIFE 100

typedef struct player_s {
    sfVector2f pos;    // Player position
    sfVector2f vel;    // Player move velocity
    float rot_vel;    // Player rotation velocity
    float speed;
    float angle;
    size_t life;
    bool flash;
} player_t;

#endif /* !PLAYER_H_ */
