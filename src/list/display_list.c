/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** my_env
*/

#include <unistd.h>
#include <stddef.h>
#include "macro.h"
#include "my.h"
#include "list.h"

static int display_node(list_t *node, void (*display_data)(void *))
{
    if (node == NULL)
        return SUCCESS;
    display_node(node->next, display_data);
    display_data(node->data);
    return SUCCESS;
}

int display_list(list_t *const *list, void (*display_data)(void *))
{
    if (list == NULL)
        return SUCCESS;
    return display_node(*list, display_data);
}
