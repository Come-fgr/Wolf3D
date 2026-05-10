/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** array_to_list
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "list.h"
#include "macro.h"
#include "my.h"

int array_to_list(char *array[], list_t **list, void *(*str_to_data)(void *))
{
    for (size_t i = 0; array[i] != NULL; i++)
        if (add_node(list, array[i], str_to_data) == ERROR)
            return ERROR;
    return SUCCESS;
}

char **list_to_array(list_t **list, void *(*data_to_str)(void *))
{
    int count = list_len(list);
    list_t *cur_node = *list;
    char **array = malloc(sizeof(char *) * (count + 1));
    int i = 0;

    if (array == NULL)
        return NULL;
    while (cur_node != NULL) {
        array[i] = data_to_str(cur_node->data);
        if (!array[i])
            return NULL;
        cur_node = cur_node->next;
        i++;
    }
    array[i] = NULL;
    return array;
}
