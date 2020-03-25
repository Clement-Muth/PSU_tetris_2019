/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** describe
*/

#include "openf.h"

static bool
init_openf(openf_t *openf, const char *restrict filepath)
{
    openf->nread = 5000;
    openf->lineptr = NULL;
    if (!(openf->stream = fopen(filepath, "r"))) {
        _putstr("failed to load file. Check the filepath\n", 2);
        return (false);
    }
    return (true);
}

bool
openf_readf(const char *restrict filepath)
{
    openf_t openf;

    if (!init_openf(&openf, filepath)) return (false);
    while (-1 != getline(&openf.lineptr, &openf.nread, openf.stream))
        _putstr(openf.lineptr, 1);
    return (true);
}