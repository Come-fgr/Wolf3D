/*
** EPITECH PROJECT, 2026
** Graphics
** File description:
** Lib graphics header
*/

#ifndef GRAPHICS_H_
    #define GRAPHICS_H_

    #include <stdbool.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Types.h>
    #include "struct/game.h"
    #include "button.h"

    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920
    #define WINDOW_NAME "my_world"
    #define FRAMERATE_LIMIT 60
    #define MAIN_SCENE MENU_START
    #define DISPLAY_ENV "DISPLAY"

bool display_env_exist(char **env);
int main_loop(void);
void update_player(game_t *game);
void update_nothing(game_t *game, const component_t *component);
void display_sprite(sfRenderWindow *window, sfSprite *sprite,
    const component_t *component);
void destroy_component(component_t *component);
sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component);
void b_start(game_t *game, const component_t *component);
void b_quit(game_t *game, const component_t *component);
void update_button(game_t *game, const component_t *component);

static const entity_t ENTITY[NB_ENT] = {
    {BUTTON, update_button, display_sprite, destroy_component},
};

static const component_t start_scene[] = {
    {BUTTON, B_QUIT, (sfVector2f){925, 550},
        (sfIntRect){0, 0, QUIT_WIDTH, QUIT_HEIGHT}, b_quit},
    {BUTTON, B_START, (sfVector2f){922, 500},
        (sfIntRect){0, 0, START_WIDTH, START_HEIGHT}, b_start},
    {NB_ENT, NB_TEXTURE, {}, {}, NULL}
};

static const component_t main_scene[] = {
    {BUTTON, B_QUIT, (sfVector2f){10, 60},
        (sfIntRect){0, 0, QUIT_WIDTH, QUIT_HEIGHT}, b_quit},
    {NB_ENT, NB_TEXTURE, {}, {}, NULL}
};

static const scene_t SCENES[NB_SCENE] = {
    {GAME, main_scene},
    {MENU_START, start_scene}
};

#endif /* !GRAPHICS_H_ */
