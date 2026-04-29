/*
** EPITECH PROJECT, 2026
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    for (; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return s1[i] - s2[i];
}
