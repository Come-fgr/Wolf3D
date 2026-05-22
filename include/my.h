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

void print_array(char **array);
void free_array(char **array);
bool check_array_malloc(void **array, size_t len_array);
char **str_to_array(char const *str, bool (*is_delimiter)(char c));
size_t array_len(char const **array);
char *concat_string(const char *first, const char *last);
long get_field_value(size_t *error, const char *str);

typedef enum {
    HELP,
    DEBUG,
    NB_FLAGS
} flag_t;

static const char FLAGS_CHAR[NB_FLAGS + 1] = "hd";

int get_index(char c, const char *str);
int get_flags(int argc, char *const *argv, bool flag_list[NB_FLAGS]);

#endif /* !MY_H_ */
