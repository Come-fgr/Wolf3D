/*
** EPITECH PROJECT, 2026
** Macro
** File description:
** Stock macro
*/

#ifndef MACRO_H
    #define MACRO_H

    // Exit status

    #define SUCCESS 0
    #define FAIL 1
    #define ERROR -1
    #define EPIFAIL 84

    // Bases

static const char DECA_BASE[] = "0123456789";
static const char HEXA_BASE[] = "0123456789abcdef";
static const char PRINT_NULL[] = "(null)";

    // Colors
static const char RED[] = "\033[31m";
static const char GREEN[] = "\033[32m";
static const char YELLOW[] = "\033[33m";
static const char BLUE[] = "\033[34m";
static const char RESET[] = "\033[0m";

    // Number of digits after the dot for mini_printf
    #define FLOAT_PRECISION 2

#endif /* !MACRO_H */
