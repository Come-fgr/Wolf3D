/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** main_loop
*/

#include <SFML/Graphics/RenderWindow.h>
#include "events/events.h"
#include "macro.h"
#include "my.h"

int main_loop(bool flag_list[NB_FLAGS])
{
    game_t game;

    if (init_game(&game, flag_list) == ERROR)
        return EPIFAIL;
    while (sfRenderWindow_isOpen(game.window)) {
        display_game(&game);
        update_game(&game);
    }
    destroy_game(&game);
    return SUCCESS;
}
