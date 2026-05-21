/*
** EPITECH PROJECT, 2025
** Libmy
** File description:
** free_list
*/

#include <stdlib.h>
#include "list.h"

void free_list(list_t *list, void (*free_data)(void *))
{
    list_t *temp = NULL;

    if (free_data == NULL)
        return;
    while (list != NULL) {
        temp = list;
        list = list->next;
        if (temp->data)
            free_data(temp->data);
        free(temp);
    }
}
