/*
** EPITECH PROJECT, 2025
** Print_array
** File description:
** Print an array of strings
*/

#include <stddef.h>
#include <stdio.h>
#include "macro.h"
#include "my.h"

void print_array(char **array)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        printf("array[%i] = %s\n", i, array[i]);
    }
}
