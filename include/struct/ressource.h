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

//! Unused
typedef enum {
    TEXTURE,
    MUSIC,
    FONT,
    NB_RESSOURCE_TYPE
} ressource_type_t;

typedef void *(create_from_file_t)(const char *);

typedef struct ressource_dir_s {
    char *name;
    char *extension;
    create_from_file_t *create_from_file;
} ressource_dir_t;

void *create_texture_from_file(const char *texture_path);

static const ressource_dir_t RESSOURCE_DIR[NB_RESSOURCE_TYPE] = {
    {"assets/sprite/", ".png",
        (create_from_file_t *)create_texture_from_file},
    {"assets/music/", ".mp3",
        (create_from_file_t *)sfMusic_createFromFile},
    {"assets/font/", ".ttf",
        (create_from_file_t *)sfFont_createFromFile}
};

typedef struct ressource_s {
    char *name;
    void *data;
} ressource_t;

#endif /* !RESSOURCE_H_ */
