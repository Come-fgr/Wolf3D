/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_life
*/

#include <stdio.h>
#include <SFML/Graphics.h>

#include "interface.h"
#include "struct/game.h"

void update_fps(game_t *game, void *data)
{
    sfText *text = data;
    char result[MAX_FPS_LABEL_LEN];

    if (!game->debug_mode)
        return;
    sprintf(result, FPS_LABEL_FORMAT, GET_FPS(game));
    sfText_setString(text, result);
}
