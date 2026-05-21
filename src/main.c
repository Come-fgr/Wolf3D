/*
** EPITECH PROJECT, 2026
** My_world
** File description:
** Main file
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "graphics.h"
#include "map.h"
#include "macro.h"

int main(int argc, char *const *argv, char *const *env)
{
    bool flag_list[NB_FLAGS] = {false};

    if (get_flags(argc, argv, flag_list) == ERROR) {
        printf("%s%s%s", HELP_MESSAGE_USAGE,
            HELP_MESSAGE_FLAG_D, HELP_MESSAGE_FLAG_H);
        return EPIFAIL;
    }
    if (!display_env_exist(env))
        return EPIFAIL;
    if (flag_list[HELP]) {
        printf("%s%s%s", HELP_MESSAGE_USAGE,
            HELP_MESSAGE_FLAG_D, HELP_MESSAGE_FLAG_H);
        return SUCCESS;
    }
    return main_loop(flag_list);
}
