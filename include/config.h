/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

    #include "struct/game.h"

void *get_config_function(const char *function_name);

void start_game(game_t *game, [[maybe_unused]] void *data);
void exit_game(game_t *game, [[maybe_unused]] void *data);

void update_life(game_t *game, void *data);
void update_stamina(game_t *game, void *data);
void update_fps(game_t *game, void *data);

typedef struct config_funct_s {
    char *name;
    void (*funct)(game_t *, [[maybe_unused]] void *data);
} config_funct_t;

static const config_funct_t CONFIG_FUNCTS[] = {
    {"_", NULL},
    {"start", start_game},
    {"quit", exit_game},
    {"update_life", update_life},
    {"update_stamina", update_stamina},
    {"update_fps", update_fps}
};

    #define NB_BUTTON LEN(CONFIG_FUNCTS)

enum {
    BUTTON_ENT,
    BUTTON_TEXTURE,
    BUTTON_POS_X,
    BUTTON_POS_Y,
    BUTTON_RECT_WIDTH,
    BUTTON_RECT_HEIGHT,
    BUTTON_FUNCT,
    BUTTON_NB_FIELDS
};

enum {
    TEXT_ENT,
    TEXT_FONT,
    TEXT_POS_X,
    TEXT_POS_Y,
    TEXT_STRING,
    TEXT_CHAR_SIZE,
    TEXT_UPDATE_FN,
    TEXT_NB_FIELDS
};

#endif /* !CONFIG_H_ */
