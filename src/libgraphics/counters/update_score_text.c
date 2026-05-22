/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** update_life
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

#include "interface.h"
#include "struct/game.h"

void update_score_text(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    size_t needed = snprintf(NULL, 0, SCORE_LABEL_FORMAT, game->score) + 1;
    char *buffer = malloc(needed);

    sprintf(buffer, SCORE_LABEL_FORMAT, game->score);
    sfText_setString(text, buffer);
}
