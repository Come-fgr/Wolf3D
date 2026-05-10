/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** add_node
*/

#include <stdlib.h>
#include <stddef.h>
#include "macro.h"
#include "list.h"

int add_node(list_t **list, void *data, void *(*data_dup)(const void *))
{
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return ERROR;
    new_node->data = data_dup(data);
    if (new_node->data == NULL)
        return ERROR;
    new_node->next = *list;
    *list = new_node;
    return SUCCESS;
}
