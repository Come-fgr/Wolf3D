/*
** EPITECH PROJECT, 2025
** File_to_str
** File description:
** Convert a file_name to a string
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "macro.h"

char *file_to_str(const char *file_name)
{
    int file = open(file_name, O_RDONLY);
    struct stat file_info = {0};
    char *str = NULL;

    if (file == ERROR || stat(file_name, &file_info) == ERROR)
        return NULL;
    str = calloc(file_info.st_size + 1, sizeof(char));
    if (str == NULL)
        return NULL;
    if (read(file, str, file_info.st_size) == ERROR)
        return NULL;
    str[file_info.st_size] = '\0';
    close(file);
    return str;
}
