/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_map
*/

#include <stdlib.h>
#include "my.h"

static bool is_break_line(char c)
{
    return c == '\n';
}

void *load_map(const char *filepath)
{
    char *str = file_to_str(filepath);
    char **map = str != NULL ? str_to_array(str, is_break_line) : NULL;

    free(str);
    return map;
}
