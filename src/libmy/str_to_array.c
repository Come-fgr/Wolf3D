/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** A function that splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell
** contains the address of a string (representing a word).
** The last cell must be null to terminate the array.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "my.h"

static char **alloc_string(char **array, char const *str,
    bool (*is_delimiter)(char c))
{
    size_t len_array = 0;
    size_t len_str = 0;
    bool error = false;
    size_t string_len = strlen(str);

    for (size_t i = 0; i <= string_len; i++) {
        if (!is_delimiter(str[i]))
            len_str++;
        if ((is_delimiter(str[i]) || !str[i]) && len_str) {
            array[len_array] = malloc((unsigned long)(len_str + 1) *
                sizeof(char));
            error = check_array_malloc((void **)array, len_array);
            len_array++;
            len_str = 0;
        }
        if (error)
            return NULL;
    }
    array[len_array] = NULL;
    return array;
}

static char **create_array(char const *str, bool (*is_delimiter)(char c))
{
    char **array = NULL;
    size_t nb_str = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (is_delimiter(str[i]))
            nb_str++;
    array = malloc((nb_str + 2) * sizeof(char *));
    if (array == NULL)
        return NULL;
    return alloc_string(array, str, is_delimiter);
}

char **str_to_array(char const *str, bool (*is_delimiter)(char c))
{
    char **array = create_array(str, is_delimiter);
    size_t len_str = 0;
    bool is_word = false;
    size_t j = 0;

    for (size_t i = 0; array == NULL && array[i] != NULL;) {
        for (j = 0; !is_delimiter(str[len_str]) && str[len_str] != '\0'; j++) {
            is_word = 1;
            array[i][j] = str[len_str];
            len_str++;
        }
        if (is_word) {
            array[i][j] = '\0';
            is_word = 0;
            i++;
        }
        len_str++;
    }
    return array;
}
