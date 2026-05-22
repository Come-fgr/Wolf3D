/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** apply_settings
*/

#include <SFML/Audio/Music.h>
#include "graphics.h"

void apply_settings(game_t *game, [[maybe_unused]] void *data)
{
    if (!game->settings.is_fullscreen && game->settings.fullscreen) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
                WINDOW_HEIGHT, 32}, WINDOW_NAME, sfFullscreen, NULL);
        game->settings.is_fullscreen = true;
    }
    if (game->settings.is_fullscreen && !game->settings.fullscreen) {
        sfRenderWindow_destroy(game->window);
        game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
                WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
        game->settings.is_fullscreen = false;
    }
}
