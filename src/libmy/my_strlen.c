/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** A function that counts and returns the number
** of characters found in the string passed as parameter
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    size_t i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
