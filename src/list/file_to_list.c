/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** file_to_list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "list.h"

list_t *file_to_list(char *filepath, size_t *nb_line)
{
    size_t line_size = 0;
    FILE *file = filepath ? fopen(filepath, "r") : NULL;
    char *line = NULL;
    list_t *list = NULL;
    int nb_char = getline(&line, &line_size, file);

    if (!file)
        return NULL;
    while (nb_char != ERROR) {
        (*nb_line)++;
        if (line[nb_char - 1] == '\n')
            line[nb_char - 1] = '\0';
        if (add_node(&list, line, (void *(*)(const void *))strdup) == ERROR) {
            free_list(list, free);
            return NULL;
        }
        nb_char = getline(&line, &line_size, file);
    }
    return list;
}
