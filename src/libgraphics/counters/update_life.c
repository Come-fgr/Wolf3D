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

void update_life(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    char result[MAX_LIFE_LABEL_LEN];

    sprintf(result, LIFE_LABEL_FORMAT, game->plr.life);
    sfText_setString(text, result);
}
