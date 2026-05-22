/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include <stdbool.h>
    #include <SFML/Graphics/RenderWindow.h>

    #define MAX_VOLUME 100
    #define DEFAULT_VOLUME 50
    #define MIN_VOLUME 0
    #define MAX_FOV 100
    #define DEFAULT_FOV (M_PI / 3.0f)
    #define MIN_FOV 0

typedef struct settings_s {
    float music_volume;
    bool fullscreen;
    float fov;
} settings_t;

#endif /* !SETTINGS_H_ */
