/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** main_loop
*/

#include <SFML/Graphics/RenderWindow.h>

#include "events/events.h"
#include "macro.h"
#include "graphics.h"

int main_loop(void)
{
    game_t game;

    if (init_game(&game) == ERROR)
        return EPIFAIL;
    while (sfRenderWindow_isOpen(game.window)) {
        display_game(&game);
        update_game(&game);
    }
    destroy_game(&game);
    return SUCCESS;
}
