/*
** EPITECH PROJECT, 2026
** private_Wolf3d
** File description:
** bs_wolf
*/

#include "bs_header.h"

static void analyse_events(sfRenderWindow *win, player_t *player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeyF))
            player->flash = !player->flash;
    }
}

static void update_player(player_t *player)
{
    const float move_speed = 150.0f;
    const float rot_speed = 2.5f;
    float dt = 1.0f / 60.0f;
    float fwd = 0.0f;

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        player->angle -= rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player->angle += rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        fwd = 1.0f;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        fwd = -1.0f;
    player->x += cosf(player->angle) * move_speed * dt * fwd;
    player->y += sinf(player->angle) * move_speed * dt * fwd;
}

int main(void)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "BS_Wolf", sfClose, NULL);
    player_t player = { 160.0f, 160.0f, (float)M_PI * 0.25f, false };

    if (!win)
        return 84;
    sfRenderWindow_setFramerateLimit(win, 60);
    while (sfRenderWindow_isOpen(win)) {
        analyse_events(win, &player);
        update_player(&player);
        draw_world(win);
        display_window(win, &player);
    }
    sfRenderWindow_destroy(win);
    return 0;
}
