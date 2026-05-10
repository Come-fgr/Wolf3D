/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <stdlib.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Font.h>
#include "macro.h"
#include "graphics.h"
#include "list.h"

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

static int init_sprite_list(component_ressource_t *sprite_list)
{
    int exit = SUCCESS;

    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++) {
        sprite_list[id].id = id;
        switch (RESSOURCE_LIST[id].type) {
            case TEXTURE:
                exit = init_sprite(&sprite_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
            case FONT:
                exit = init_font(&sprite_list[id],
                    RESSOURCE_LIST[id].ressource_path);
                break;
        }
        if (exit == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

static int init_component(component_t *component_list,
    component_ressource_t ressource_list[NB_RESSOURCE])
{
    entity_t entity = {};
    component_ressource_t ressource = {};
    int exit = SUCCESS;

    for (size_t i = 0; component_list[i].entity != NB_ENT; i++) {
        entity = ENTITY[component_list[i].entity];
        ressource = ressource_list[component_list[i].texture];
        if (entity.init != NULL)
            exit = entity.init(&component_list[i], &ressource);
        if (exit == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

static int init_scene(component_ressource_t ressource_list[NB_RESSOURCE],
    scene_t scene_list[NB_SCENE])
{
    size_t nb_line = 0;
    list_t *scene = file_to_list("config/start_scene.config", &nb_line);
    char **scene_array = NULL;

    if (scene != NULL)
        scene_array = list_to_array(&scene, line_dup);
    for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++)
        if (init_component(scene_list[scene_id].component_list, ressource_list)
            == ERROR)
            return ERROR;
    free_list(scene, free);
    free_array(scene_array);
    return SUCCESS;
}

int init_game(game_t *game, scene_t scene_list[NB_SCENE])
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->event = malloc(sizeof(sfEvent));
    game->clock = sfClock_create();
    error += init_sprite_list(game->sprite_list);
    if (error || !game->window || !game->event || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    if (init_scene(game->sprite_list, scene_list) == ERROR) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
