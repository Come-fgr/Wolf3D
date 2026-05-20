/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** load_ressource
*/

#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Audio/Music.h>
#include "macro.h"
#include "my.h"
#include "list.h"
#include "struct/ressource.h"

static int clean(char *name, sfTexture *texture)
{
    if (name != NULL)
        free(name);
    if (texture != NULL)
        sfTexture_destroy(texture);
    return ERROR;
}

void *create_texture_from_file(const char *texture_path)
{
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);

    if (texture == NULL)
        return NULL;
    return texture;
}

static char *get_ressource_name(const char *filepath, const char *exetension)
{
    size_t len = strlen(filepath);
    size_t exetension_len = strlen(exetension);
    int name_len = len - exetension_len;

    if (name_len < 1)
        return NULL;
    return strndup(filepath, name_len);

}

static int add_ressource_to_list(list_t **ressource_list,
    const char *filepath, const ressource_dir_t *ressource_dir,
    bool flag_list[NB_FLAGS])
{
    list_t *new_node = calloc(1, sizeof(list_t));
    ressource_t *ressource = calloc(1, sizeof(ressource_t));
    char *full_path = concat_string(ressource_dir->name, filepath);

    if (new_node == NULL || ressource == NULL || full_path == NULL)
        return ERROR;
    ressource->name = get_ressource_name(filepath, ressource_dir->extension);
    ressource->type = ressource_dir->type;
    ressource->data = ressource_dir->create_from_file(full_path);
    if (ressource->data == NULL || ressource->name == NULL)
        return ERROR; //! Free error
    new_node->data = ressource;
    new_node->next = *ressource_list;
    *ressource_list = new_node;
    if (flag_list[DEBUG])
        minidprintf(STDOUT_FILENO, "Ressource \"%s\" loaded from \"%s\"\n",
            ressource->name, filepath);
    return SUCCESS;
}

static int load_ressource(list_t **ressource_list,
    const ressource_dir_t *ressource_dir, bool flag_list[NB_FLAGS])
{
    DIR *dir = opendir(ressource_dir->name);
    struct dirent *entry = NULL;

    if (dir == NULL)
        return ERROR;
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.')
            if (add_ressource_to_list(ressource_list, entry->d_name,
                    ressource_dir, flag_list) == ERROR)
                return ERROR; //! Free error
        entry = readdir(dir);
    }
    if (flag_list[DEBUG])
        minidprintf(STDOUT_FILENO, "%sAll %s successfully loaded%s\n",
            GREEN, ressource_dir->name, RESET);
    closedir(dir);
    return SUCCESS;
}

int init_ressource_list(list_t **ressource_list,
    bool flag_list[NB_FLAGS])
{
    for (ressource_type_t id = 0; id < NB_RESSOURCE_TYPE; id++)
        if (load_ressource(ressource_list, &RESSOURCE_DIR[id], flag_list)
            == ERROR)
            return ERROR;
    if (flag_list[DEBUG])
        minidprintf(STDOUT_FILENO, "%sRessources successfully loaded%s\n",
            GREEN, RESET);
    return SUCCESS;
}
