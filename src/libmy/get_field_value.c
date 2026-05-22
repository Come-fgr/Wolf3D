/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_field_value
*/

#include <stddef.h>
#include <stdlib.h>
#include "my/my_string.h"
#include "macro.h"

long get_field_value(size_t *error, const char *str)
{
    char *endptr = NULL;
    long result = strtol(str, &endptr, STRLEN(DECA_BASE));

    *error += *endptr != '\0';
    return result;
}

float get_field_value_f(size_t *error, const char *str)
{
    char *endptr = NULL;
    long result = strtof(str, &endptr);

    *error += *endptr != '\0';
    return result;
}
