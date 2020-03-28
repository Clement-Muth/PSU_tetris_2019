/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [WSL: Debian]
** File description:
** _strlen
*/

#include "string.h"

size_t
_strlen(char *restrict string)
{
    char *ptr = string;

    for (; *ptr; ptr++);
    return ptr - string;
}