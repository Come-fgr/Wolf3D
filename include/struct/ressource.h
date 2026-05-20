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
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio/Music.h>

typedef enum {
    B_QUIT,
    B_START,
    TITANFALL_FONT,
    BT_MUSIC,
    NB_RESSOURCE
} ressource_id_t;

typedef enum {
    TEXTURE,
    MUSIC,
    FONT,
} ressource_type_t;

typedef struct ressource_s {
    ressource_id_t id;
    char *name;
    ressource_type_t type;
    char *ressource_path;
} ressource_t;

    #include "button.h"

static const ressource_t RESSOURCE_LIST[NB_RESSOURCE] = {
    {B_QUIT, "quit", TEXTURE, QUIT_TEXTURE},
    {B_START, "start", TEXTURE, START_TEXTURE},
    {TITANFALL_FONT, "titanfall", FONT, "assets/font/titanfall.ttf"},
    {BT_MUSIC, "BT-7274", MUSIC, "assets/music/BT-7274.mp3"}
};

typedef struct component_ressource_s {
    ressource_id_t id;
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfMusic *music;
} component_ressource_t;

static const char ASSETS_DIR[] = "assets";
static const char SPRITE_DIR[] = "assets/sprite";

//typedef struct ressource_dir_s {
//    char *name;
//    char *extension
//    ressource_type_t type;
//} ressource_dir_t;
//
//static const ressource_dir_t RESSOURCE_DIR[NB_RESSOURCE_TYPE] = {
//    {"sprite", ".png" TEXTURE},
//    {"music", MUSIC},
//    {"font", FONT}
//};

typedef struct ressource_bis_s {
    char *name;
    ressource_type_t type;
    void *data;
} ressource_bis_t;

#endif /* !RESSOURCE_H_ */
