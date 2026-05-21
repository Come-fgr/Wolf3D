/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** get_ressource
*/

#include <string.h>
#include "macro.h"
#include "list.h"
#include "struct/ressource.h"


void *get_ressource(const char *ressource_name, list_t **ressource_list)
{
    list_t *current = *ressource_list;
    ressource_t *ressource = (ressource_t *)current->data;

    while (current != NULL) {
        ressource = (ressource_t *)current->data;
        if (strcmp(ressource_name, ressource->name) == SUCCESS)
            return ressource->data;
        current = current->next;
    }
    return NULL;
}
