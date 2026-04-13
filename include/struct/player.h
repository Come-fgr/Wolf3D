/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <SFML/System/Vector2.h>

typedef struct player_s {
    sfVector2f *pos;
    float angle;
} player_t;

#endif /* !PLAYER_H_ */
