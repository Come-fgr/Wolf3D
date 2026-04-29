#include "bs_header.h"

static sfColor shade_color(sfColor base, float corrected_dist, bool flash)
{
    if (corrected_dist > COLOR_MAX) {
        return (sfColor){0,0,0,255};
    } else if (flash) {
        int v = (int)(COLOR_MAX - corrected_dist + corrected_dist * 0.30f);
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        return (sfColor){(sfUint8)v,(sfUint8)v,(sfUint8)v,255};
    } else {
        int v = (int)(COLOR_MAX - corrected_dist);
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        return (sfColor){(sfUint8)v,(sfUint8)v,(sfUint8)v,255};
    }
}

static void analyse_events(sfRenderWindow *win, player_t player)
{
    sfEvent event;
    
    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape) sfRenderWindow_close(win);
            if (event.key.code == sfKeyF) player.flash = !player.flash;
        }
    }
}

static player_t update_player(player_t player)
{
    const float move_speed = 150.0f;
    const float rot_speed = 2.5f;
    float dt = 1.0f / 60.0f;
    float fwd = 0.0f;

    if (sfKeyboard_isKeyPressed(sfKeyQ)) player.angle -= rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyD)) player.angle += rot_speed * dt;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) fwd = 1.0f;
    if (sfKeyboard_isKeyPressed(sfKeyS)) fwd = -1.0f;
    player.x += cosf(player.angle) * move_speed * dt * fwd;
    player.y += sinf(player.angle) * move_speed * dt * fwd;
    return player;
}

static void draw_world(sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);

    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){WIN_WIDTH, WIN_HEIGHT/2.0f});
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rect, (sfColor){80,80,120,255}); /* ceiling */
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, WIN_HEIGHT/2.0f});
    sfRectangleShape_setFillColor(rect, (sfColor){60,140,60,255}); /* floor */
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
    sfRectangleShape_destroy(rect);
}

int main(void)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "Bootsrap Wolf", sfClose, NULL);
    player_t player = { 160.0f, 160.0f, (float)M_PI * 0.25f, false };
    float half_fov = 0.0;
    float angle_step = 0.0;

    if (!win)
        return 1;
    sfRenderWindow_setFramerateLimit(win, 60);

    while (sfRenderWindow_isOpen(win)) {
        analyse_events(win, player);
        player = update_player(player);
        draw_world(win);

        half_fov = FOV / 2.0f;
        angle_step = FOV / (float)NUM_RAYS;
        for (int col = 0; col < NUM_RAYS; ++col) {
            float ray_angle = player.angle - half_fov + ((float)col + 0.5f) * angle_step;
            float hitx=0, hity=0;
            int wall_id=0;
            float raw_dist = cast_single_ray(&player, ray_angle, &hitx, &hity, &wall_id);
            float corrected = raw_dist * cosf(ray_angle - player.angle);
            if (corrected <= 0) corrected = 0.0001f;
            float wall_height = (TILE_SIZE * 277.0f) / corrected;
            float top = (WIN_HEIGHT / 2.0f) - (wall_height / 2.0f);

            sfRectangleShape *colrect = sfRectangleShape_create();
            sfRectangleShape_setSize(colrect, (sfVector2f){1.0f, wall_height});
            sfRectangleShape_setPosition(colrect, (sfVector2f){(float)col, top});

            int texoff = ((int)hitx + (int)hity) % TILE_SIZE;

            sfColor base = wall_color_for_id(wall_id);
            sfColor shaded = shade_color(base, corrected, player.flash);
            sfRectangleShape_setFillColor(colrect, shaded);

            sfRenderWindow_drawRectangleShape(win, colrect, NULL);
            sfRectangleShape_destroy(colrect);
        }
        // minimap(win);

        sfRenderWindow_display(win);
    }

    sfRenderWindow_destroy(win);
    return 0;
}
