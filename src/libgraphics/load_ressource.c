/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_ressource
*/

#include <dirent.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Font.h>
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

static int load_ressource(ressource_bis_t *ressources)
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

static int init_sprite(component_ressource_t *ressource, char *texture_path)
{
    ressource->texture = sfTexture_createFromFile(texture_path, NULL);
    if (!ressource->texture)
        return ERROR;
    ressource->sprite = sfSprite_create();
    if (!ressource->sprite)
        return ERROR;
    sfSprite_setTexture(ressource->sprite, ressource->texture,
        sfTrue);
    return SUCCESS;
}

static int init_font(component_ressource_t *ressource, char *font_path)
{
    ressource->font = sfFont_createFromFile(font_path);
    if (ressource->font == NULL)
        return ERROR;
    return SUCCESS;
}

//TODO: Use load_ressource + add MUSIC
int init_ressource_list(component_ressource_t *ressource_list)
{
    int exit = SUCCESS;

    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++) {
        ressource_list[id].id = id;
        ressource_list[id].name = my_strdup(RESSOURCE_LIST[id].name);
        switch (RESSOURCE_LIST[id].type) {
            case TEXTURE:
                exit = init_sprite(&ressource_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
            case FONT:
                exit = init_font(&ressource_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
        }
        if (exit == ERROR)
            return ERROR;
    }
    return SUCCESS;
}