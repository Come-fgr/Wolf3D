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

int main(int argc, char *argv[], char *env[])
{
    if (!display_env_exist(env))
        return EPIFAIL;
    if (argc == 1)
        return main_loop();
    if (argc == 2 && strcmp(argv[1], "-h") == SUCCESS) {
        puts("./wolf3d:\n\tIn progress...");
        return SUCCESS;
    }
    return EPIFAIL;
}
