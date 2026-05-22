/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** ressource
*/

#ifndef RESSOURCE_H_
    #define RESSOURCE_H_

    #include <stddef.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio/Music.h>
    #include "my.h"

typedef enum {
    TEXTURE,
    MUSIC,
    FONT,
    MAP,
    NB_RESSOURCE_TYPE
} ressource_type_t;

typedef void *(create_from_file_t)(const char *);
typedef void (destroy_funct_t)(void *);

typedef struct ressource_dir_s {
    char *name;
    char *extension;
    ressource_type_t type;
    create_from_file_t *create_from_file;
    destroy_funct_t *destroy;
} ressource_dir_t;

void *create_texture_from_file(const char *texture_path);
void *load_map(const char *filepath);

static const ressource_dir_t RESSOURCE_DIR[NB_RESSOURCE_TYPE] = {
    {"assets/sprite/", ".png", TEXTURE,
        (create_from_file_t *)create_texture_from_file,
        (destroy_funct_t *)sfTexture_destroy},
    {"assets/music/", ".mp3", MUSIC,
        (create_from_file_t *)sfMusic_createFromFile,
        (destroy_funct_t *)sfMusic_destroy},
    {"assets/font/", ".ttf", FONT,
        (create_from_file_t *)sfFont_createFromFile,
        (destroy_funct_t *)sfFont_destroy},
    {"assets/map/", ".map", MAP, load_map, (destroy_funct_t *)free_array}
};

typedef struct ressource_s {
    char *name;
    ressource_type_t type;
    void *data;
} ressource_t;

#endif /* !RESSOURCE_H_ */
