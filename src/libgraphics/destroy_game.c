/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Destroy game objects
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/RenderWindow.h>
#include "graphics.h"

static void free_ressource(ressource_t *ressource)
{
    if (ressource != NULL) {
        if (ressource->data)
            RESSOURCE_DIR[ressource->type].destroy(ressource->data);
        if (ressource->name)
            free(ressource->name);
        free(ressource);
    }
}

static void destroy_scene(scene_t *scene)
{
    component_t **component_list = scene->component_list;

    if (component_list == NULL)
        return;
    for (entity_id_t index = 0; component_list[index] != NULL; index++)
        if (ENTITY[component_list[index]->entity].destroy != NULL)
            ENTITY[component_list[index]->entity].destroy(
                component_list[index]);
    free(component_list);
}

static void destroy_scene_list(scene_t *scene_list)
{
    for (scene_id_t scene_id = 0; scene_id < NB_SCENE; scene_id++)
        destroy_scene(&scene_list[scene_id]);
}

void destroy_game(game_t *game)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->clock != NULL)
        sfClock_destroy(game->clock);
    if (game->ressource_list != NULL) {
        free_list(*game->ressource_list, (void (*)(void *))free_ressource);
        free(game->ressource_list);
    }
    destroy_scene_list(game->scene_list);
}
