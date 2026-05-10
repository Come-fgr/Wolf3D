/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** file_to_list
*/

#include <stdio.h>
#include <stdlib.h>
#include "macro.h"
#include "list.h"
#include "my.h"

void *line_dup(const void *line)
{
    return my_strdup((char *)line);
}

list_t *file_to_list(char *filepath, int *nb_line)
{
    size_t line_size = 0;
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    list_t *list = NULL;

    if (!file)
        return NULL;
    while (getline(&line, &line_size, file) != ERROR) {
        (*nb_line)++;
        if (add_node(&list, line, line_dup) == ERROR) {
            free_list(list, free);
            return NULL;
        }
    }
    return list;
}
