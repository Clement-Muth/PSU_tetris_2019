/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [WSL: Debian]
** File description:
** _putchar
*/

#include "string.h"

void
_putchar(const char character, const int fd)
{
    write(fd, &character, 1);
}