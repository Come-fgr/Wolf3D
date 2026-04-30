/*
** EPITECH PROJECT, 2026
** My_world
** File description:
** Main file
*/

#include <unistd.h>
#include "graphics.h"
#include "my.h"
#include "map.h"
#include "macro.h"

int main(int argc, char *const *argv, char *const *env)
{
    bool flag_list[NB_FLAGS] = {false};

    if (get_flags(argc, argv, flag_list) == ERROR)
        return EPIFAIL;
    if (!display_env_exist(env))
        return EPIFAIL;
    if (argc == 1)
        return main_loop();
    if (flag_list[HELP]) {
        minidprintf(STDOUT_FILENO, "./wolf3d:\n\tIn progress...\n");
        return SUCCESS;
    }
    return EPIFAIL;
}
