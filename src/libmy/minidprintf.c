/*
** EPITECH PROJECT, 2025
** myprintf
** File description:
** Functions that print char, string and number.
*/

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "macro.h"
#include "my.h"

size_t my_putchar(int std, char c)
{
    return write(std, &c, 1);
}

size_t my_putstr(int std, char const *str)
{
    if (str == NULL)
        return write(std, PRINT_NULL, my_strlen(PRINT_NULL));
    return write(std, str, my_strlen(str));
}

size_t my_putnbr_base(int std, long long nbr, char const *base)
{
    unsigned long long unbr = nbr;
    size_t base_len = my_strlen(base);
    size_t count = 0;

    if (nbr < 0) {
        count += my_putchar(std, '-');
        count += my_putnbr_base(std, -nbr, base);
    } else if (unbr >= base_len) {
        count += my_putnbr_base(std, unbr / base_len, base);
        count += my_putnbr_base(std, unbr % base_len, base);
    } else {
        count += my_putchar(std, base[unbr]);
    }
    return count;
}

static size_t put_zero(int std, double dec_digits, size_t digits)
{
    size_t count = 0;

    dec_digits *= 10;
    for (count = 0; dec_digits < 1 && dec_digits > -1 &&
        count < digits - 1; count++) {
        my_putchar(std, '0');
        dec_digits *= 10;
    }
    return count;
}

size_t my_putfloat_base(int std, double nbr, char const *base, size_t digits)
{
    double round_nbr = my_round(nbr, digits);
    size_t base_len = my_strlen(base);
    double dec_digits = ABS((round_nbr - (long long)round_nbr) *
        my_pow(base_len, digits));
    long long dec_int = (long long)(dec_digits + 0.5);
    size_t count = my_putnbr_base(std, round_nbr, base);

    if (digits > 0)
        count += my_putchar(std, '.') +
            put_zero(std, round_nbr - (long long)round_nbr, digits) +
            my_putnbr_base(std, dec_int, base);
    return count;
}

static size_t print_args(int std, char flag, va_list args)
{
    switch (flag) {
        case 'c':
            return my_putchar(std, va_arg(args, int));
        case 's':
            return my_putstr(std, va_arg(args, char *));
        case 'i':
            return my_putnbr_base(std, va_arg(args, int), DECA_BASE);
        case 'f':
            return my_putfloat_base(std, va_arg(args, double), DECA_BASE,
                FLOAT_PRECISION);
        default:
            return my_putchar(std, '%');
    }
}

size_t minidprintf(int std, const char *format, ...)
{
    size_t count = 0;
    va_list args;

    if (format == NULL)
        return count;
    va_start(args, format);
    for (size_t i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            count += print_args(std, format[i], args);
        } else {
            count += my_putchar(std, format[i]);
        }
    }
    va_end(args);
    return count;
}
