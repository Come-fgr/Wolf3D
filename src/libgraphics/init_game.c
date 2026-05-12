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
#include "my.h"

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

//TODO: Use get_dir_content + add MUSIC
static int init_sprite_list(component_ressource_t *sprite_list)
{
    int exit = SUCCESS;

    for (ressource_id_t id = 0; id < NB_RESSOURCE; id++) {
        sprite_list[id].id = id;
        sprite_list[id].name = my_strdup(RESSOURCE_LIST[id].name);
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

//! To delete
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
            exit = entity.init(&component_list[i], NULL, &ressource);
        if (exit == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

bool is_sep(char c)
{
    return c == SEPARATOR;
}

static component_t *str_to_component(char *str, component_ressource_t
    ressource_list[NB_RESSOURCE])
{
    component_t *component = calloc(1, sizeof(component_t));
    char **array = str_to_array(str, is_sep);

    if (component == NULL || array == NULL)
        return NULL;
    for (entity_id_t id = 0; id < NB_ENT; id++)
        if (my_strcmp(ENTITY[id].name, array[0]) == SUCCESS) {
            return ENTITY[id].init(component, array, ressource_list) == ERROR ?
                NULL : component;
        }
    return NULL;
}

static int init_scene(scene_t *scene, char *config_file,
    component_ressource_t ressource_list[NB_RESSOURCE])
{
    size_t nb_comp = 0;
    list_t *scene_config = file_to_list(config_file, &nb_comp);
    component_t *scene_array = calloc(nb_comp + 1, sizeof(component_t *));

    if (scene_config == NULL && scene_array == NULL)
        return ERROR;
    if (list_to_array(&scene_config, (void **)&scene_array,
        (void *(*)(const void *, component_ressource_t
        [NB_RESSOURCE]))str_to_component, ressource_list) == ERROR)
        return ERROR;
    free_list(scene_config, free);
    scene->component_list = scene_array;
    return SUCCESS;
}

//TODO: Use init_scene
static int init_scene_list(component_ressource_t ressource_list[NB_RESSOURCE],
    scene_t scene_list[NB_SCENE])
{
    for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++)
        if (init_component(scene_list[scene_id].component_list, ressource_list)
            == ERROR)
            return ERROR;
    return SUCCESS;
}

int init_game(game_t *game, scene_t scene_list[NB_SCENE])
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->event = calloc(1,sizeof(sfEvent));
    game->clock = sfClock_create();
    error += init_sprite_list(game->sprite_list);
    if (error || !game->window || !game->event || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    if (init_scene_list(game->sprite_list, scene_list) == ERROR) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
