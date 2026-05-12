/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** array_len
*/

#include <stddef.h>

size_t array_len(char const **array)
{
    size_t i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

