/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** Round a double to the number digits given in argument
*/

#include "my.h"

double my_round(double nbr, size_t digits)
{
    double pow_ten = my_pow(10, digits);
    long long int_res = (long long)(nbr * pow_ten);
    size_t carry_over = ((long long)((nbr * pow_ten) * 10) % 10 >= 5) ? 1 : 0;

    return (int_res + carry_over) / pow_ten;
}
