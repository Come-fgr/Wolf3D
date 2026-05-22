/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/View.h>
#include "macro.h"
#include "graphics.h"
#include "list.h"
#include "my.h"
#include "map.h"

static component_t *str_to_component(char *str, list_t
    **ressource_list, bool flag_list[NB_FLAGS])
{
    component_t *component = calloc(1, sizeof(component_t));
    char **array = str_to_array(str, is_sep);
    component_t *exit_value = NULL;

    if (component == NULL || array == NULL)
        return NULL;
    for (entity_id_t id = 0; id < NB_ENT; id++) {
        if (strcmp(ENTITY[id].name, array[0]) == SUCCESS) {
            exit_value = ENTITY[id].init(component, (const char **)array,
                ressource_list, flag_list) == ERROR ? NULL : component;
            free_array(array);
            return exit_value;
        }
    }
    free_array(array);
    return NULL;
}

static int list_to_component_array(list_t **list, component_t **array,
    list_t **ressource_list,
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
    return SUCCESS;
}

static int init_scene(scene_t *scene, char *config_file,
    list_t **ressource_list,
    bool flag_list[NB_FLAGS])
{
    size_t nb_comp = 0;
    list_t *scene_config = file_to_list(config_file, &nb_comp);
    component_t **scene_array = calloc(nb_comp + 1, sizeof(component_t *));

    if (scene_config == NULL && scene_array == NULL)
        return ERROR;
    if (list_to_component_array(&scene_config, scene_array,
            ressource_list, flag_list) == ERROR)
        return ERROR;
    free_list(scene_config, free);
    scene->component_list = scene_array;
    if (flag_list[DEBUG])
        printf("%sScene \"%s\" successfully initialized%s\n"
            , GREEN, config_file, RESET);
    return SUCCESS;
}

static int init_scene_list(list_t **ressource_list,
    scene_t scene_list[NB_SCENE], bool flag_list[NB_FLAGS])
{
    for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++) {
        if (init_scene(&scene_list[scene_id], SCENES_CONFIG[scene_id].file,
                ressource_list, flag_list) == ERROR)
            return ERROR;
        scene_list[scene_id].music = SCENES_CONFIG[scene_id].music != NULL ?
            (sfMusic *)get_ressource(SCENES_CONFIG[scene_id].music,
            ressource_list) : NULL;
        if (scene_list[scene_id].music != NULL)
            sfMusic_setLoop(scene_list[scene_id].music, sfTrue);
    }
    return SUCCESS;
}

void init_player(player_t *plr)
{
    plr->pos = (sfVector2f){ MAP_CENTER_X - 16.0f, MAP_CENTER_Y - 16.0f };
    plr->angle = (float)M_PI * 0.25f;
    plr->speed = DEFAULT_PLR_SPEED;
    plr->life = PLR_MAX_LIFE;
    plr->stamina = PLR_MAX_STAMINA;
    plr->flash = false;
    plr->rot_vel = PLR_ROTATE_VALUE;
    plr->running = false;
    plr->vel = (sfVector2f){0, 0};
}

int init_game(game_t *game, bool flag_list[NB_FLAGS])
{
    load_settings(&game->settings);
    game->window = create_window(game->settings.fullscreen);
    game->clock = sfClock_create();
    game->ressource_list = calloc(1, sizeof(list_t *));
    game->debug_mode = flag_list[DEBUG];
    init_player(&game->plr);
    game->cur_music = NULL;
    if (!game->window || !game->clock || !game->ressource_list)
        return ERROR;
    *game->ressource_list = NULL;
    if (init_ressource_list(game->ressource_list, flag_list) == ERROR)
        return ERROR;
    if (init_scene_list(game->ressource_list, game->scene_list,
            flag_list) == ERROR)
        return ERROR;
    game->cur_scene = MENU_START;
    game->prev_scene = NB_SCENE;
    game->run = true;
    return SUCCESS;
}
