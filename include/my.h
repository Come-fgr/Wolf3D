/*
** EPITECH PROJECT, 2026
** My_H
** File description:
** Lib header
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <stdbool.h>

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
char *my_strdup(char const *src);
void print_array(char **array);
void free_array(char **array);
bool check_array_malloc(void **array, size_t len_array);
char **str_to_array(char const *str, bool (*is_delimiter)(char c));
size_t array_len(char const **array);
char *concat_string(const char *first, const char *last);

typedef enum {
    HELP,
    DEBUG,
    NB_FLAGS
} flag_t;

static const char FLAGS_CHAR[NB_FLAGS + 1] = "hd";

int get_index(char c, const char *str);
int get_flags(int argc, char *const *argv, bool flag_list[NB_FLAGS]);

#endif /* !MY_H_ */
