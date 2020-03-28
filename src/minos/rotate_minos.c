/*
** EPITECH PROJECT, 2020
** rotates a piece
** File description:
** rotates
*/

#include "../../include/my.h"
#include "../../include/minos.h"

static void copy_column(char **new, minos_t *minos, int i)
{
    int k = 0;
    int column = ((int)minos->width * 2) - (i * 2) - 2;

    for (int j = 0; j < minos->height; ++j) {
        if (j != 0)
            new[i][k++] = ' ';
        new[i][k++] = minos->minos[j][column];
    }
    new[i][(int)minos->height * 2 - 1] = '\0';
}

static void fill_new(char **new, minos_t *minos)
{
    for (int i = 0; i < minos->width; ++i) {
        copy_column(new, minos, i);
    }
    new[(int)minos->width] = NULL;
}

int rotate_minos(minos_t *minos)
{
    char **ret;
    char temp = 0;

    if (!minos || !(ret = malloc(sizeof(char *) * (minos->width + 1))))
        return (1);
    for (int i = 0; i < minos->width; ++i) {
        if (!(ret[i] = malloc(minos->height * 2))) {
            free_done((void **)ret, i);
            return (1);
        }
    }
    fill_new(ret, minos);
    temp = minos->height;
    minos->height = minos->width;
    minos->width = temp;
    multi_free("2", minos->minos);
    minos->minos = ret;
    return (0);
}
