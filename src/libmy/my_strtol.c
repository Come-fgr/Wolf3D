/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** A function that returns a number,
** sent to the function as a string
*/

#include "my.h"

size_t my_isdigits(char c)
{
    return '0' <= c && c <= '9';
}

long my_strtol(char const *str, char **restrict endptr)
{
    long res = 0;
    int sign = 1;
    int is_sign = 1;
    int len = my_strlen(str);
    size_t i;

    for (i = 0; str[i] != 0; i++) {
        if (str[i] == '-' && is_sign)
            sign = -sign;
        if (my_isdigits(str[i])) {
            is_sign = 0;
            res += (str[i] - '0') * my_pow(10, (len - 1) - i);
        }
        if (!((str[i] == '-' || str[i] == '+') && is_sign)
            && !my_isdigits(str[i]))
            return (res / my_pow(10, len - i)) * sign;
    }
    *endptr = (char *)&str[i];
    return res * sign;
}
