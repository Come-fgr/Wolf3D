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

int array_to_list(char *array[], list_t **list,
    void *(*str_to_data)(const void *))
{
    for (size_t i = 0; array[i] != NULL; i++)
        if (add_node(list, array[i], str_to_data) == ERROR)
            return ERROR;
    return SUCCESS;
}

int list_to_array(list_t **list, void **array,
    void *(*convert_data)(const void *))
{
    list_t *cur_node = *list;
    size_t i = 0;

    if (array == NULL)
        return ERROR;
    while (cur_node != NULL) {
        array[i] = convert_data(cur_node->data);
        if (array[i] == NULL)
            return ERROR;
        cur_node = cur_node->next;
        i++;
    }
    array[i] = NULL;
    return SUCCESS;
}
