/*
** EPITECH PROJECT, 2025
** Free_array
** File description:
** Free an array
*/

#include <stddef.h>
#include <stdlib.h>

void free_array(char **array)
{
    if (array != NULL) {
        for (size_t i = 0; array[i] != NULL; i++)
            free(array[i]);
        free(array);
    }
}
