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

static const button_funct_t BUTTON_FUNCT[NB_BUTTON] = {
    {"start", b_start},
    {"quit", b_quit}
};

#endif /* !CONFIG_H_ */
