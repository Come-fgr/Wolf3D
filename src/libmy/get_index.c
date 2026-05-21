/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_index
*/

#include <stddef.h>
#include "macro.h"

int get_index(char c, const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return ERROR;
}
