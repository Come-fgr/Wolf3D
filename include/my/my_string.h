/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** string
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    ///////////////////////////////////
    //    Type checking assertions   //
    ///////////////////////////////////

    // Returns a bool showing if a char is a digit
    #define IS_DIGIT(x) (x >= '0' && x <= '9')
    // Returns a bool showing if a char is a lowercase
    #define IS_LOWERCASE(x) (x >= 'a' && x <= 'z')
    // Returns a bool showing if a char is an uppercase
    #define IS_UPPERCASE(x) (x >= 'A' && x <= 'Z')
    // Returns a bool showing if a char is a letter
    #define IS_LETTER(x) (IS_LOWERCASE(x) || IS_UPPERCASE(x))

    ///////////////////////////////////
    //     Transform chars macros    //
    ///////////////////////////////////

    // Returns a letter to uppercase
    #define TO_UPPERCASE(x) (IS_LOWERCASE(x) ? x + 'A' - 'a' : x)
    // Returns a letter to lowercase
    #define TO_LOWERCASE(x) (IS_UPPERCASE(x) ? x + 'a' - 'A' : x)

    ///////////////////////////////////
    //            Others             //
    ///////////////////////////////////

    // Returns the len of a string macro
    #define STRLEN(x) (sizeof(x) / sizeof(x[0]) - 1)

#endif /* !MY_STRING_H_ */
