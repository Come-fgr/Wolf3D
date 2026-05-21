/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** player_sprint
*/

#include "struct/game.h"

void player_sprint_start(game_t *game)
{
    if (game == NULL || game->plr.stamina <= 0)
        return;
    game->plr.speed = DEFAULT_PLR_SPEED * SPRINT_FACTOR;
    game->plr.running = true;
}

void player_sprint_stop(game_t *game)
{
    if (game == NULL)
        return;
    game->plr.speed = DEFAULT_PLR_SPEED;
    game->plr.running = false;
}
