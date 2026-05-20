/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_ressource
*/

#include "macro.h"
#include "graphics.h"
#include "my.h"

#include <stdio.h>

void *get_ressource(const char *ressource_name, list_t **ressource_list)
{
    list_t *current = *ressource_list;
    ressource_t *ressource = (ressource_t *)current->data;

    while (current != NULL) {
        ressource = (ressource_t *)current->data;
        if (my_strcmp(ressource_name, ressource->name) == SUCCESS)
            return ressource->data;
        current = current->next;
    }
    return NULL;
}
