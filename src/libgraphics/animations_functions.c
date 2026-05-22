/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** animations_functions
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>

#include "list.h"
#include "my_string.h"
#include "my.h"
#include "macro.h"
#include "graphics.h"
#include "config.h"
#include "castray.h"

static animation_t *create_animation(const char **config, sfTexture *texture,
    sfVector2f *pos, size_t *error)
{
    animation_t *data = calloc(1, sizeof(animation_t));

    if (data == NULL)
        return NULL;
    data->rect.width = get_field_value(error, config[ANIMATION_RECT_WIDTH]);
    data->rect.height = get_field_value(error, config[ANIMATION_RECT_HEIGHT]);
    data->rect.left = 0;
    data->rect.top = 0;
    data->seconds = get_field_value_f(error, config[ANIMATION_SPEED]);
    data->count = 0;
    data->nb_frame = get_field_value(error, config[ANIMATION_NB_FRAME]);
    data->sprite = create_sprite(texture, &data->rect, pos);
    *error += data->sprite == NULL;
    return data;
}

static size_t set_animation_variables(component_t *component,
    const char **config, list_t **ressource_list)
{
    size_t error = SUCCESS;
    sfTexture *texture = get_ressource(config[ANIMATION_TEXTURE],
        ressource_list);

    component->entity = ANIMATION;
    component->pos.x = get_field_value(&error, config[ANIMATION_POS_X]);
    component->pos.y = get_field_value(&error, config[ANIMATION_POS_Y]);
    component->data = create_animation(config, texture, &component->pos,
        &error);
    error += component->data == NULL;
    return error;
}

int init_animation(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS])
{
    size_t error = SUCCESS;

    if (array_len(config) != ANIMATION_NB_FIELDS) {
        if (flag_list[DEBUG])
            dprintf(STDERR_FILENO, "%sError: Wrong array size\n%s\n",
                RED, RESET);
        return ERROR;
    }
    error = set_animation_variables(component, config, ressource_list);
    if (flag_list[DEBUG])
        printf("Load animation \"%s\" = %s%s%s\n",
            config[ANIMATION_TEXTURE], error == SUCCESS ? GREEN : RED,
            error == SUCCESS ? "success" : "error", RESET);
    return error != SUCCESS ? ERROR : SUCCESS;
}

static void move_rect(sfIntRect *rect, size_t nb_frame)
{
    size_t offset = rect->width;
    size_t max_value = offset * (nb_frame - 1);

    if ((size_t)rect->left >= max_value) {
        rect->left = 0;
    } else {
        rect->left += offset;
    }
}

void update_animation(game_t *game, const component_t *component)
{
    animation_t *animation = component->data;

    animation->count += game->delta_time;
    if (animation->count >= animation->seconds) {
        move_rect(&animation->rect, animation->nb_frame);
        sfSprite_setTextureRect(animation->sprite, animation->rect);
        animation->count = 0;
    }
}

void display_animation(sfRenderWindow *window, const component_t *component)
{
    animation_t *animation = component->data;

    sfRenderWindow_drawSprite(window, animation->sprite, NULL);
}

void destroy_animation(component_t *component)
{
    animation_t *animation = component->data;

    sfSprite_destroy(animation->sprite);
    free(animation);
    free(component);
}
