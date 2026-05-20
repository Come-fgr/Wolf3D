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

//TODO: Check if argv contains non-flag
int main(int argc, char *const *argv, char *const *env)
{
    bool flag_list[NB_FLAGS] = {false};

    if (get_flags(argc, argv, flag_list) == ERROR)
        return EPIFAIL;
    if (!display_env_exist(env))
        return EPIFAIL;
    if (flag_list[HELP]) {
        minidprintf(STDOUT_FILENO, HELP_MESSAGE);
        return SUCCESS;
    }
    return main_loop(flag_list);
}
