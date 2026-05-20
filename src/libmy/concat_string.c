/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** concat_string
*/

#include <stdlib.h>
#include <string.h>

char *concat_string(const char *first, const char *last)
{
    char *res = calloc((strlen(first) + strlen(last) + 1), sizeof(char));

    if (res == NULL)
        return NULL;
    res[0] = '\0';
    strcat(res, first);
    strcat(res, last);
    return res;
}
