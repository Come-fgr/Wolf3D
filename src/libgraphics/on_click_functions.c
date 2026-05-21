/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** on_click_functions
*/

#include <SFML/Graphics/RenderWindow.h>
#include "struct/game.h"

void start_game(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    game->cur_scene = GAME;
}

void exit_game(game_t *game, [[maybe_unused]] void *data)
{
    if (game == NULL)
        return;
    sfRenderWindow_close(game->window);
}
