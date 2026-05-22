/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** save_system
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "macro.h"
#include "struct/game.h"
#include "save_system.h"

void save_settings(game_t *game, [[maybe_unused]] void *data)
{
    int fd = open(SAVE_FILE_SETTINGS, O_WRONLY | O_TRUNC | O_CREAT,
        S_IRWXU | S_IRWXG | S_IRWXO);

    if (game == NULL || fd == ERROR)
        return;
    dprintf(fd, "%f;%f;%u", game->settings.music_volume,
        game->settings.fov,
        game->settings.fullscreen);
    close(fd);
}
