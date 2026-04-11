/*
** EPITECH PROJECT, 2026
** My_H
** File description:
** Lib header
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>

    #define ABS(value) value < 0 ? -value : value

size_t minidprintf(int std, const char *format, ...);
size_t my_putfloat_base(int std, double nbr, char const *base, size_t digits);
size_t my_putnbr_base(int std, long long nbr, char const *base);
size_t my_putstr(int std, char const *str);
size_t my_putchar(int std, char c);
long long my_pow(int nb, int p);
double my_round(double nbr, size_t digits);
size_t my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
long my_strtol(char const *str, char **restrict endptr);

#endif /* !MY_H_ */
