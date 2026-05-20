/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Initialize main struct
*/

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "macro.h"
#include "graphics.h"
#include "list.h"
#include "my.h"

bool is_sep(char c)
{
    return c == SEPARATOR;
}

static component_t *str_to_component(char *str, list_t
    **ressource_list, bool flag_list[NB_FLAGS])
{
    component_t *component = calloc(1, sizeof(component_t));
    const char **array = (const char **)str_to_array(str, is_sep);

    if (component == NULL || array == NULL)
        return NULL;
    for (entity_id_t id = 0; id < NB_ENT; id++)
        if (my_strcmp(ENTITY[id].name, array[0]) == SUCCESS) {
            return ENTITY[id].init(component, array, ressource_list, flag_list)
                == ERROR ? NULL : component;
        }
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

//TODO: Free in case of errors
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
        minidprintf(STDOUT_FILENO, "%sScene \"%s\" successfully initialized%s\n"
            , GREEN, config_file, RESET);
    return SUCCESS;
}

//TODO: Use get_dir_content
static int init_scene_list(list_t **ressource_list,
    scene_t scene_list[NB_SCENE], bool flag_list[NB_FLAGS])
{
    //for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++)
    if (init_scene(&scene_list[MENU_START], "config/start_scene.config",
            ressource_list, flag_list) == ERROR)
        return ERROR;
    if (init_scene(&scene_list[GAME], "config/game_scene.config",
            ressource_list, flag_list) == ERROR)
        return ERROR;
    return SUCCESS;
}

static void init_player(player_t *plr)
{
    plr->pos = (sfVector2f){ 160.0f, 160.0f };
    plr->angle = (float)M_PI * 0.25f;
    plr->speed = DEFAULT_PLR_SPEED;
}

int init_game(game_t *game, bool flag_list[NB_FLAGS])
{
    game->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
            WINDOW_HEIGHT, 32}, WINDOW_NAME, sfClose, NULL);
    game->clock = sfClock_create();
    game->ressource_list = calloc(1, sizeof(list_t *));
    game->plr = (player_t){0};
    init_player(&game->plr);
    if (!game->window || !game->clock || !game->ressource_list) {
        destroy_game(game);
        return ERROR;
    }
    *game->ressource_list = NULL;
    if (init_ressource_list(game->ressource_list, flag_list) == ERROR) {
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
