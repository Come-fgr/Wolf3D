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

void b_start(game_t *game, const component_t *component)
{
    if (game->event->type == sfEvtMouseButtonPressed &&
        is_clicked(game->window, component))
        game->cur_scene = GAME;
}

void b_quit(game_t *game, const component_t *component)
{
    if (game->event->type == sfEvtMouseButtonPressed &&
        is_clicked(game->window, component))
        sfRenderWindow_close(game->window);
}
