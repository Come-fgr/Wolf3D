/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** A function that allocates memory and copies the string
** given as argument in it.
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    size_t i = 0;
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = calloc(my_strlen(src) + 1, sizeof(char));
    if (dest == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
