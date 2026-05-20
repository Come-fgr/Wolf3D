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


typedef enum {
    TEXTURE,
    MUSIC,
    FONT,
    NB_RESSOURCE_TYPE
} ressource_type_t;


static const char ASSETS_DIR[] = "assets";
static const char SPRITE_DIR[] = "assets/sprite";

typedef void *(create_from_file_t)(const char *);

typedef struct ressource_dir_s {
    char *name;
    char *extension;
    ressource_type_t type;
    create_from_file_t *create_from_file;
} ressource_dir_t;

void *create_texture_from_file(const char *texture_path);

static const ressource_dir_t RESSOURCE_DIR[NB_RESSOURCE_TYPE] = {
    {"assets/sprite/", ".png", TEXTURE,
        (create_from_file_t *)create_texture_from_file},
    {"assets/music/", ".mp3", MUSIC,
        (create_from_file_t *)sfMusic_createFromFile},
    {"assets/font/", ".ttf", FONT,
        (create_from_file_t *)sfFont_createFromFile}
};

typedef struct ressource_s {
    char *name;
    ressource_type_t type;
    void *data;
} ressource_t;

#endif /* !RESSOURCE_H_ */
