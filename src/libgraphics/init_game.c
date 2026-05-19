/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include "macro.h"
#include "graphics.h"
#include "list.h"
#include "my.h"

//! To delete
//static int init_component(component_t *component_list,
//    component_ressource_t ressource_list[NB_RESSOURCE])
//{
//    entity_t entity = {};
//    component_ressource_t ressource = {};
//    int exit = SUCCESS;
//
//    for (size_t i = 0; component_list[i].entity != NB_ENT; i++) {
//        entity = ENTITY[component_list[i].entity];
//        ressource = ressource_list[component_list[i].texture];
//        if (entity.init != NULL)
//            exit = entity.init(&component_list[i], NULL, &ressource);
//        if (exit == ERROR)
//            return ERROR;
//    }
//    return SUCCESS;
//}

bool is_sep(char c)
{
    return c == SEPARATOR;
}

static component_t *str_to_component(char *str, component_ressource_t
    ressource_list[NB_RESSOURCE], bool flag_list[NB_FLAGS])
{
    component_t *component = calloc(1, sizeof(component_t));
    char **array = str_to_array(str, is_sep);

    if (component == NULL || array == NULL)
        return NULL;
    for (entity_id_t id = 0; id < NB_ENT; id++)
        if (my_strcmp(ENTITY[id].name, array[0]) == SUCCESS) {
            if (flag_list[DEBUG])
                minidprintf(STDOUT_FILENO, "Init component \"%s\" of entity type \"%s\"\n",
                str, ENTITY[id].name);
            return ENTITY[id].init(component, array, ressource_list, flag_list)
                == ERROR ? NULL : component;
        }
    return NULL;
}

static int list_to_component_array(list_t **list, component_t **array,
    component_ressource_t ressource_list[NB_RESSOURCE],
    bool flag_list[NB_FLAGS])
{
    list_t *cur_node = *list;
    size_t i = 0;

    if (array == NULL)
        return ERROR;
    while (cur_node != NULL) {
        array[i] = str_to_component(cur_node->data, ressource_list, flag_list);
        if (array[i] == NULL)
            return ERROR;
        cur_node = cur_node->next;
        i++;
    }
    array[i] = NULL;
    if (flag_list[DEBUG])
        minidprintf(STDOUT_FILENO, "%sComponent successfully initialized%s\n",
            GREEN, RESET);
    return SUCCESS;
}

//TODO: Free in case of errors
static int init_scene(scene_t *scene, char *config_file,
    component_ressource_t ressource_list[NB_RESSOURCE],
    bool flag_list[NB_FLAGS])
{
    size_t nb_comp = 0;
    list_t *scene_config = file_to_list(config_file, &nb_comp);
    component_t **scene_array = calloc(nb_comp + 1, sizeof(component_t *));

    if (scene_config == NULL && scene_array == NULL)
        return ERROR;
    if (list_to_component_array(&scene_config, (void **)scene_array,
        ressource_list, flag_list) == ERROR)
        return ERROR;
    free_list(scene_config, free);
    scene->component_list = scene_array;
    return SUCCESS;
}

//TODO: Use different config file
static int init_scene_list(component_ressource_t ressource_list[NB_RESSOURCE],
    scene_t scene_list[NB_SCENE], bool flag_list[NB_FLAGS])
{
    for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++)
        //if (init_component(scene_list[scene_id].component_list, ressource_list)
        if (init_scene(&scene_list[scene_id], "config/start_scene.config",
            ressource_list, flag_list)
            == ERROR)
            return ERROR;
    return SUCCESS;
}

int init_game(game_t *game, bool flag_list[NB_FLAGS])
{
    int error = SUCCESS;

    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->event = calloc(1,sizeof(sfEvent));
    game->clock = sfClock_create();
    error += init_ressource_list(game->ressource_list, flag_list);
    if (error || !game->window || !game->event || !game->clock) {
        destroy_game(game);
        return ERROR;
    }
    if (init_scene_list(game->ressource_list, game->scene_list,
        flag_list) == ERROR) {
        destroy_game(game);
        return ERROR;
    }
    sfRenderWindow_setFramerateLimit(game->window, FRAMERATE_LIMIT);
    game->cur_scene = MENU_START;
    return SUCCESS;
}
