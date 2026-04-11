/*
** EPITECH PROJECT, 2026
** My_world
** File description:
** Main file
*/

#include <unistd.h>
#include "graphics.h"
#include "my.h"
#include "macro.h"

int main(int argc, char *argv[], char *env[])
{
    if (!display_env_exist(env))
        return EPIFAIL;;
    if (argc == 1)
        return main_loop();
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        minidprintf(STDOUT_FILENO, "./wolf3d:\n\tIn progress...\n");
        return SUCCESS;
    }
    return EPIFAIL;
}
