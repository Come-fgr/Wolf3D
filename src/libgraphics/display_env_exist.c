/*
** EPITECH PROJECT, 2026
** Libgraphics
** File description:
** display_env_exist
*/

#include <string.h>
#include "graphics.h"
#include "macro.h"

bool display_env_exist(char **env)
{
    size_t len = strlen(DISPLAY_ENV);

    if (env == NULL)
        return false;
    for (size_t i = 0; env[i] != NULL; i++)
        if (strncmp(env[i], DISPLAY_ENV, len) == SUCCESS)
            return true;
    return false;
}
