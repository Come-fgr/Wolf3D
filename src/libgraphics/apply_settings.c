/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** apply_settings
*/

#include <SFML/Audio/Music.h>
#include "struct/game.h"

void apply_settings(game_t *game, [[maybe_unused]] void *data)
{
    if (game->cur_music != NULL)
        sfMusic_setVolume(game->cur_music, game->settings.music_volume);
    return;
}
