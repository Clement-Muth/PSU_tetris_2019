/*
** EPITECH PROJECT, 2020
** library [WSL: Debian]
** File description:
** openf_init
*/

#include "openf.h"

static void
init_struct(openf_t *openf)
{
    openf->lineptr = NULL;
    openf->stream = NULL;
    openf->nline = 0;
    openf->nread = 0;
}

static bool
openf_readf_and_count(openf_t *openf, const char *restrict filepath)
{
    if (!(openf->stream = fopen(filepath, "r"))) {
        _putstr("failed to load file. Check the filepath\n", 2);
        return (false);
    }
    while (-1 != getline(&openf->lineptr, &openf->nread, openf->stream))
        openf->nline++;
    return (true);
}

openf_t *
openf_init(const char *restrict filepath, size_t nread)
{
    openf_t *openf = malloc(sizeof(openf_t));

    if (!openf) return (NULL);
    init_struct(openf);
    if (!openf_readf_and_count(openf, filepath)) return (NULL);
    return (openf);
}