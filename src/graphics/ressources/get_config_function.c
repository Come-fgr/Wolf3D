/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** get_config_function
*/

#include <string.h>
#include "config.h"
#include "macro.h"

void *get_config_function(const char *function_name)
{
    for (size_t id = 0; id < NB_BUTTON; id++)
        if (strcmp(function_name, CONFIG_FUNCTS[id].name) == SUCCESS)
            return CONFIG_FUNCTS[id].funct;
    return NULL;
}
