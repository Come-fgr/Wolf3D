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

void update_stamina(game_t *game, [[maybe_unused]] void *data)
{
    sfText *text = data;
    char result[MAX_STAMINA_LABEL_LEN];

    sprintf(result, STAMINA_LABEL_FORMAT, (size_t)game->plr.stamina);
    sfText_setString(text, result);
}
