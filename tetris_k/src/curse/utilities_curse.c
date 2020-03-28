/*
** EPITECH PROJECT, 2020
** tetris_k [WSL: Debian]
** File description:
** utilities_curse
*/

#include <ncurses.h>
#include "../../include/define.h"
#include "../../include/minos.h"
#include "../../include/library/_string/include/string.h"
#include "../../include/my.h"

static int
minos_len(minos_t **minos)
{
    int ret = 0;

    while (minos[ret])
        ++ret;
    return (ret);
}

static minos_t *
cpy_minos(minos_t *minos)
{
    minos_t *ret = malloc(sizeof(minos_t));

    if (!ret)
        return (ret);
    ret->minos = my_char2dup(minos->minos);
    ret->name = my_strdup(minos->name);
    ret->width = minos->width;
    ret->height = minos->height;
    ret->pos = minos->pos;
    return (ret);
}

minos_t *
get_random(minos_t **minos)
{
    int mrand = rand() % minos_len(minos);

    return (cpy_minos(minos[mrand]));
}