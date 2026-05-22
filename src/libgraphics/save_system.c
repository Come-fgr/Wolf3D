/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** save_system
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "macro.h"
#include "graphics.h"
#include "save_system.h"
#include "config.h"

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

void save_player(game_t *game, [[maybe_unused]] void *data)
{
    int fd = open(SAVE_FILE_PLAYER, O_WRONLY | O_TRUNC | O_CREAT,
        S_IRWXU | S_IRWXG | S_IRWXO);

    if (game == NULL || fd == ERROR)
        return;
    dprintf(fd, "%f;%f;%f;%lu;%u", game->plr.pos.x, game->plr.pos.y,
        game->plr.angle, game->plr.life, game->plr.flash);
    close(fd);
}

void load_player(game_t *game, [[maybe_unused]] void *data)
{
    size_t error = SUCCESS;
    char *str = file_to_str(SAVE_FILE_PLAYER);
    char **config = str != NULL ? str_to_array(str, is_sep) : NULL;

    if (config == NULL || array_len((const char **)config) !=
        PLAYER_NB_FIELDS) {
        free(str);
        free_array(config);
        return;
    }
    game->plr.pos.x = get_field_value_f(&error, config[PLAYER_POS_X]);
    game->plr.pos.y = get_field_value_f(&error, config[PLAYER_POS_Y]);
    game->plr.angle = get_field_value_f(&error, config[PLAYER_ANGLE]);
    game->plr.life = get_field_value(&error, config[PLAYER_LIFE]);
    game->plr.flash = (bool)get_field_value(&error, config[PLAYER_FLASH]);
    if (error != SUCCESS)
        init_player(&game->plr);
    start_game(game, NULL);
}
