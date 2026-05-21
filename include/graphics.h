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

    #define WINDOW_HEIGHT 1080
    #define WINDOW_WIDTH 1920
    #define WINDOW_NAME "Wolf3d"
    #define FRAMERATE_LIMIT 60
    #define MAIN_SCENE MENU_START
    #define DISPLAY_ENV "DISPLAY"
    #define SEPARATOR ';'

// Help message
static const char HELP_MESSAGE_USAGE[] = "Usage: ./wolf3d [OPTION]\n";
static const char HELP_MESSAGE_FLAG_H[] = "\t-h\tDisplay this help and exit\n";
static const char HELP_MESSAGE_FLAG_D[] =
    "\t-d\tDisplay log messages during initialization\n";

// Error handling
bool display_env_exist(char *const *const env);

// Initialization
int init_ressource_list(list_t **ressource_list,
    bool flag_list[NB_FLAGS]);
int init_button(component_t *component, const char **config,
    list_t **ressource_list,
    bool flag_list[NB_FLAGS]);
int init_text(component_t *component, const char **config,
    list_t **ressource_list, bool flag_list[NB_FLAGS]);
void *get_ressource(const char *ressource_name, list_t **ressource_list);

// Update
int main_loop(bool flag_list[NB_FLAGS]);
void update_player(player_t *plr, float delta);

// Display
void display_button(sfRenderWindow *window, const component_t *component);
void display_text(sfRenderWindow *, const component_t *);

// Destroy
void destroy_button(component_t *component);
void destroy_text(component_t *);

// Events
sfBool is_clicked(const sfMouseButtonEvent *evt, const component_t *component);

//Entities list
static const entity_t ENTITY[NB_ENT] = {
    {BUTTON, "button", init_button, NULL, display_button,
        destroy_button, CLICKABLE},
    {TEXT, "text", init_text, NULL, display_text, destroy_text,
        NO_PROPERTIES}
};

// Component structs
typedef struct text_s {
    sfText *text;
    char *string;
    size_t size;
} text_t;

#endif /* !GRAPHICS_H_ */
