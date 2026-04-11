/*
** EPITECH PROJECT, 2025
** my_pow
** File description:
** An iterative function that returns
** the first argument raised to the power p,
** where p is the second argument
*/

#include <stddef.h>

long long my_pow(int nb, int p)
{
    long long res = 1;

    if (p < 0)
        return 1;
    for (size_t i = 0; i < (size_t)p; i++) {
        res = res * nb;
    }
    return res;
}
