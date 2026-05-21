/*
** EPITECH PROJECT, 2025
** Libmy
** File description:
** A function called list_len
** that returns the number of elements on the list.
*/

#include <stddef.h>
#include "list.h"

size_t list_len(list_t *const *begin)
{
    list_t *current_node = *begin;
    size_t len;

    for (len = 0; current_node != NULL; len++)
        current_node = current_node->next;
    return len;
}
