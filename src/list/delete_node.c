/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include <stddef.h>
#include "macro.h"
#include "my.h"
#include "list.h"

int delete_node(list_t **list, list_t *prev_node, list_t *current_node,
    void (*free_data)(void *))
{
    list_t *temp = current_node;

    current_node = current_node->next;
    if (prev_node == NULL)
        *list = current_node;
    else
        prev_node->next = current_node;
    free_data(temp->data);
    free(temp);
    return SUCCESS;
}
