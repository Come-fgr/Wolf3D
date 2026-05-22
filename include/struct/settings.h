/*
** EPITECH PROJECT, 2026
** Wolf3D
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include <SFML/Graphics/RenderWindow.h>

typedef struct settings_s {
    float music_volume;
    sfVideoMode window_mode;
    float fov;
} settings_t;

#endif /* !SETTINGS_H_ */
