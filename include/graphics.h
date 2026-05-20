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
    #define WINDOW_NAME "Wolf3d"
    #define FRAMERATE_LIMIT 60
    #define MAIN_SCENE MENU_START
    #define DISPLAY_ENV "DISPLAY"
    #define SEPARATOR ';'

// Update

int main_loop(bool flag_list[NB_FLAGS]);
void update_player(player_t *plr, float delta);

// Display

bool display_env_exist(char *const *const env);
void display_sprite(sfRenderWindow *window, sfSprite *sprite,
    const component_t *component);

// Destroy

void destroy_component(component_t *component);

// Events

sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component);
void b_start(game_t *game);
void b_quit(game_t *game);
void update_button(game_t *game, const component_t *component);
int init_ressource_list(component_ressource_t *ressource_list,
    bool flag_list[NB_FLAGS]);
int init_button(component_t *component, const char **config,
    component_ressource_t ressource_list[NB_RESSOURCE],
    bool flag_list[NB_FLAGS]);
int init_text(component_t *component, const char **config, component_ressource_t
    ressource_list[NB_RESSOURCE], bool flag_list[NB_FLAGS]);
void display_text(sfRenderWindow *, sfSprite *,
    const component_t *);
void destroy_text(component_t *);

static const char HELP_MESSAGE[] =
    "Usage: ./wolf3d [OPTION]\n\t-h\tDisplay this help and exit\n";

//Entities list
static const entity_t ENTITY[NB_ENT] = {
    {BUTTON, "button", init_button, update_button, display_sprite,
        destroy_component, CLICKABLE},
    {TEXT, "text", init_text, NULL, display_text, destroy_text,
        NO_PROPERTIES}
};

typedef struct button_funct_s {
    char *name;
    void (*funct)(game_t *);
} button_funct_t;

    #define NB_BUTTON 2

static const button_funct_t BUTTON_FUNCT[NB_BUTTON] = {
    {"start", b_start},
    {"quit", b_quit}
};

typedef struct text_s {
    sfText *text;
    char *string;
    size_t size;
} text_t;


#endif /* !GRAPHICS_H_ */
