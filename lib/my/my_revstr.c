/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int stlen = 0;
    int max = 0;
    int c = 0;

    for (stlen; str[stlen] != '\0'; stlen++);
    max = stlen / 2;
    for (i; i < stlen; i++) {
        c = str[i];
        str[i] = str[stlen - 1];
        str[stlen - 1] = c;
        stlen--;
    }
    return (str);
}
