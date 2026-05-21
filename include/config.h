/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

    #include "struct/game.h"

void b_start(game_t *game);
void b_quit(game_t *game);

typedef struct button_funct_s {
    char *name;
    void (*funct)(game_t *);
} button_funct_t;

    #define NB_BUTTON 2

static const button_funct_t BUTTON_FUNCT_LIST[NB_BUTTON] = {
    {"start", b_start},
    {"quit", b_quit}
};

enum {
    BUTTON_ENT,
    BUTTON_TEXTURE,
    BUTTON_POS_X,
    BUTTON_POS_Y,
    BUTTON_RECT_WIDTH,
    BUTTON_RECT_HEIGHT,
    BUTTON_FUNCT,
    BUTTON_CONFIG,
};

enum {
    TEXT_ENT,
    TEXT_FONT,
    TEXT_POS_X,
    TEXT_POS_Y,
    TEXT_STRING,
    TEXT_CHAR_SIZE,
    TEXT_CONFIG,
};

#endif /* !CONFIG_H_ */
