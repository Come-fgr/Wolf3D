/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_player
*/

#include "castray.h"

void updating_player(players_t *player)
{
    const float move_speed = 150.0f;
    const float rot_speed = 2.5f;
    float dt = 1.0f / 60.0f;
    float fwd = 0.0f;

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        player->angle -= rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player->angle += rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        fwd = 1.0f;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        fwd = -1.0f;
    player->x += cosf(player->angle) * move_speed * dt * fwd;
    player->y += sinf(player->angle) * move_speed * dt * fwd;
}
