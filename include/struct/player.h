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

    #define DEFAULT_PLR_POS_X 659.0f
    #define DEFAULT_PLR_POS_Y 634.0f
    #define DEFAULT_PLR_POS (sfVector2f){DEFAULT_PLR_POS_X, DEFAULT_PLR_POS_Y}
    #define DEFAULT_PLAYER_ANGLE (M_PI * 0.25f)

    #define INTERACT_DIST TILE_SIZE * 0.75f

    // player.pos incrementing value per second
    #define DEFAULT_PLR_SPEED 150.0f

    #define SPRINT_FACTOR 2

    // player.angle rotate value per second
    #define PLR_ROTATE_VALUE 2.5f

    #define PLR_MAX_LIFE 100
    #define PLR_MAX_STAMINA 100.0f

    #define STAMINA_RUN_COST 10.0f
    #define STAMINA_REGEN 5.0f

typedef struct player_s {
    sfVector2f pos;    // Player position
    sfVector2f vel;    // Player move velocity
    float rot_vel;     // Player rotation velocity
    float speed;
    float angle;
    size_t life;
    float stamina;
    bool flash;
    bool running;
} player_t;

#endif /* !PLAYER_H_ */
