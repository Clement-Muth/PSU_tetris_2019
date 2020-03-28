/*
** EPITECH PROJECT, 2020
** library [WSL: Debian]
** File description:
** openf_assign
*/

#include "openf.h"

char **openf_assign(const char *restrict filepath)
{
    openf_t *openf = openf_init(filepath, 500);
    char **filecontent = _memalloc(sizeof(char *) * openf->nline);
}