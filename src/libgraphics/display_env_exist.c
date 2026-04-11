/*
** EPITECH PROJECT, 2026
** Libgraphics
** File description:
** display_env_exist
*/

#include "graphics.h"
#include "my.h"

bool display_env_exist(char **env)
{
    size_t len = my_strlen(DISPLAY_ENV);

    if (env == NULL)
        return false;
    for (size_t i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], DISPLAY_ENV, len) == 0)
            return true;
    return false;
}
