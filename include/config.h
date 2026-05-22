/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** config
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

    #include "struct/game.h"
    #include "events/keys.h"

void *get_config_function(const char *function_name);

void start_game(game_t *game, [[maybe_unused]] void *data);
void exit_game(game_t *game, [[maybe_unused]] void *data);
void go_to_settings_scene(game_t *game, [[maybe_unused]] void *data);
void go_to_start_scene(game_t *game, [[maybe_unused]] void *data);

void increase_music_volume(game_t *game, [[maybe_unused]] void *data);
void decrease_music_volume(game_t *game, [[maybe_unused]] void *data);
void increase_fov(game_t *game, [[maybe_unused]] void *data);
void decrease_fov(game_t *game, [[maybe_unused]] void *data);
void change_window_mode(game_t *game, [[maybe_unused]] void *data);

void update_life(game_t *game, void *data);
void update_stamina(game_t *game, void *data);
void update_fps(game_t *game, void *data);
void update_volume_text(game_t *game, [[maybe_unused]] void *data);
void update_fov_text(game_t *game, [[maybe_unused]] void *data);
void update_fullscreen_text(game_t *game, [[maybe_unused]] void *data);

void apply_settings(game_t *game, [[maybe_unused]] void *data);
void save_settings(game_t *game, [[maybe_unused]] void *data);
void save_player(game_t *game, [[maybe_unused]] void *data);
void load_player(game_t *game, [[maybe_unused]] void *data);

typedef struct config_funct_s {
    char *name;
    event_fnct_t funct;
} config_funct_t;

static const config_funct_t CONFIG_FUNCTS[] = {
    {"_", NULL},
    {"start", start_game},
    {"quit", exit_game},
    {"pause", got_to_prev_scene},
    {"settings", go_to_settings_scene},
    {"+volume", increase_music_volume},
    {"-volume", decrease_music_volume},
    {"+fov", increase_fov},
    {"-fov", decrease_fov},
    {"fullscreen", change_window_mode},
    {"update_life", update_life},
    {"update_stamina", update_stamina},
    {"update_fps", update_fps},
    {"update_volume", update_volume_text},
    {"update_fov", update_fov_text},
    {"update_fullscreen", update_fullscreen_text},
    {"apply_settings", apply_settings},
    {"prev_scene", got_to_prev_scene},
    {"menu_start", go_to_start_scene},
    {"save_settings", save_settings},
    {"save_player", save_player},
    {"load_player", load_player}
};

    #define NB_BUTTON LEN(CONFIG_FUNCTS)

enum {
    BUTTON_ENT,
    BUTTON_TEXTURE,
    BUTTON_POS_X,
    BUTTON_POS_Y,
    BUTTON_RECT_WIDTH,
    BUTTON_RECT_HEIGHT,
    BUTTON_FONT,
    BUTTON_STRING,
    BUTTON_CHAR_SIZE,
    BUTTON_FUNCT,
    BUTTON_NB_FIELDS
};

enum {
    TEXT_ENT,
    TEXT_FONT,
    TEXT_POS_X,
    TEXT_POS_Y,
    TEXT_STRING,
    TEXT_CHAR_SIZE,
    TEXT_UPDATE_FN,
    TEXT_NB_FIELDS
};

enum {
    ANIMATION_ENT,
    ANIMATION_TEXTURE,
    ANIMATION_POS_X,
    ANIMATION_POS_Y,
    ANIMATION_RECT_WIDTH,
    ANIMATION_RECT_HEIGHT,
    ANIMATION_SPEED,
    ANIMATION_NB_FRAME,
    ANIMATION_NB_FIELDS
};

enum {
    PLAYER_POS_X,
    PLAYER_POS_Y,
    PLAYER_ANGLE,
    PLAYER_LIFE,
    PLAYER_FLASH,
    PLAYER_NB_FIELDS
};

enum {
    SETTINGS_VOLUME,
    SETTINGS_FOV,
    SETTINGS_FULLSCREEN,
    SETTINGS_NB_FIELDS
};

#endif /* !CONFIG_H_ */
