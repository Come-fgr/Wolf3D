/*
** EPITECH PROJECT, 2026
** Libgraphics
** File description:
** button_function
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "SFML/Graphics/RenderWindow.h"
#include "graphics.h"

void b_start(game_t *game)
{
    game->cur_scene = GAME;
}

void b_quit(game_t *game)
{
    sfRenderWindow_close(game->window);
}
