/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_ressource
*/

#include <dirent.h>
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include "macro.h"
#include "my.h"
#include "struct/ressource.h"

static int clean(char *name, sfTexture *texture)
{
    if (name != NULL)
        free(name);
    if (texture != NULL)
        sfTexture_destroy(texture);
    return ERROR;
}

int load_ressource(ressource_bis_t *ressources)
{
    DIR *dir = opendir(SPRITE_DIR);
    struct dirent *entry = readdir(dir);

    for (size_t i = 0; entry != NULL; i++) {
        if (entry->d_name[0] != '.') {
            ressources[i].name = my_strdup(entry->d_name);
            ressources[i].type = TEXTURE;
            ressources[i].data = sfTexture_createFromFile(entry->d_name, NULL);
            if (ressources[i].data == NULL || ressources[i].name == NULL)
                return clean(ressources[i].name, ressources[i].data);
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return SUCCESS;
}
