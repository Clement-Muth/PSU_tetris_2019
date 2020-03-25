/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [WSL: Debian]
** File description:
** _putstr
*/

#include "string.h"

void
_putstr(const char *restrict string, const int fd)
{
    do
        _putchar(*string, fd);
    while (*string++);
}