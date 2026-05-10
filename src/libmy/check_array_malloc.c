/*
** EPITECH PROJECT, 2025
** Check array malloc
** File description:
** Check malloc and free the array if it fail
*/

#include <stdlib.h>
#include <stdbool.h>

bool check_array_malloc(void **array, size_t len_array)
{
    if (array[len_array] == NULL) {
        for (size_t j = 0; j < len_array; j++)
            free(array[j]);
        free(array);
        return true;
    }
    return false;
}
