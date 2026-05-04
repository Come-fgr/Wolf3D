/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** main_loop
*/

#include <SFML/Graphics/RenderWindow.h>
#include "macro.h"
#include "graphics.h"

int main_loop(void)
{
    game_t game;

    if (init_game(&game, SCENES) == ERROR)
        return EPIFAIL;
    while (sfRenderWindow_isOpen(game.window)) {
        display_game(&game, SCENES);
        update_game(&game, SCENES);
    }
    destroy_game(&game);
    return SUCCESS;
}
