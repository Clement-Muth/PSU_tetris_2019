/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [WSL: Debian]
** File description:
** strcp
*/

#include "string.h"

bool
_strcmp(const char *restrict comparing, const char *restrict compared)
{
    while (*compared++ == *comparing++ && *compared && *comparing);
    return (*compared == 0) ? (true) : (false);
}