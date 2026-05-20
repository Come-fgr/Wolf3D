/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_flags
*/

#include <stdbool.h>
#include <getopt.h>
#include "macro.h"
#include "my.h"

int get_flags(int argc, char *const *argv, bool flag_list[NB_FLAGS])
{
    int opt = ERROR;
    int index = ERROR;

    for (int i = 1; i < argc; i++)
        if (argv[i][0] != '-')
            return ERROR;
    opt = getopt(argc, argv, FLAGS_CHAR);
    while (opt != ERROR) {
        index = get_index(opt, FLAGS_CHAR);
        if (index == ERROR)
            return ERROR;
        flag_list[index] = true;
        opt = getopt(argc, argv, FLAGS_CHAR);
    }
    return SUCCESS;
}
