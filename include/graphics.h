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

bool display_env_exist(char *const *env);
int main_loop(void);
void update_nothing(game_t *game, const component_t *component);
void display_sprite(sfRenderWindow *window, sfSprite *sprite,
    const component_t *component);
void destroy_component(component_t *component);
sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component);
void b_start(game_t *game, const component_t *component);
void b_quit(game_t *game, const component_t *component);
void update_button(game_t *game, const component_t *component);
int init_text(component_t *component,
    component_ressource_t sprite_list[NB_RESSOURCE]);
void display_text(sfRenderWindow *, sfSprite *,
    const component_t *);
void destroy_text(component_t *);

static const entity_t ENTITY[NB_ENT] = {
    {BUTTON, NULL, update_button, display_sprite, destroy_component},
    {TEXT, init_text, update_nothing, display_text, destroy_text}
};

typedef struct text_s {
    sfText *text;
    char *string;
    size_t size;
} text_t;


static component_t start_scene[] = {
    {BUTTON, B_QUIT, (sfVector2f){925, 550},
        (sfIntRect){0, 0, QUIT_WIDTH, QUIT_HEIGHT}, b_quit},
    {BUTTON, B_START, (sfVector2f){922, 500},
        (sfIntRect){0, 0, START_WIDTH, START_HEIGHT}, b_start},
    {TEXT, TITANFALL_FONT, (sfVector2f){50, 50}, (sfIntRect){0}, &(text_t){NULL,
            "Wolfenstein3D", 20}},
    {NB_ENT, NB_RESSOURCE, {}, {}, NULL}
};

static component_t main_scene[] = {
    {BUTTON, B_QUIT, (sfVector2f){10, 60},
        (sfIntRect){0, 0, QUIT_WIDTH, QUIT_HEIGHT}, b_quit},
    {NB_ENT, NB_RESSOURCE, {}, {}, NULL}
};

static scene_t SCENES[NB_SCENE] = {
    {GAME, main_scene},
    {MENU_START, start_scene}
};

#endif /* !GRAPHICS_H_ */
