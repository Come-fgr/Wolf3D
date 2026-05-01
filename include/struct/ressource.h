/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** ressource
*/

#ifndef RESSOURCE_H_
    #define RESSOURCE_H_

static const char SPRITE_DIR[] = "assets/sprite";

typedef enum {
    TEXTURE,
    MUSIC,
    FONT,
    NB_RESSOURCE_TYPE
} ressource_type_t;

//typedef struct ressource_dir_s {
//    char *name;
//    ressource_type_t type;
//} ressource_dir_t;
//
//static const ressource_dir_t RESSOURCE_DIR[NB_RESSOURCE_TYPE] = {
//    {"assets/sprite", TEXTURE},
//    {"", MUSIC},
//    {"", FONT}
//};

typedef struct ressource_s {
    char *name;
    ressource_type_t type;
    void *data;
} ressource_t;

#endif /* !RESSOURCE_H_ */
