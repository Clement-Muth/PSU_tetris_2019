/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copies
*/

#include "../../include/my.h"

int my_strcpy(char *dest, char *src)
{
    if (dest == NULL || )
    while (*dest && *src) {
        *dest = *src;
        ++dest;
        ++src;
    }
    return (0);
}
