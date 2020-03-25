/*
** EPITECH PROJECT, 2020
** adapt_minos
** File description:
** adapt_minos
*/

#include "../../include/my.h"
#include "../../include/minos.h"

static void swap(minos_t **first, minos_t **second)
{
    minos_t *temp = *first;

    *first = *second;
    *second = temp;
}

static int is_first(minos_t **minos, int place)
{
    for (int i = place; minos[i]; ++i) {
        if (str_compare(minos[place]->name, minos[i]->name) == 0) {
            return (0);
        }
    }
    return (1);
}

static void sort_minos(minos_t **minos)
{
    int j = 0;

    for (int i = 0; minos[i]; ++i) {
        j = i;
        while (is_first(minos, j) == 0) {
            ++j;
        }
        if (j != i)
            swap(&minos[i], &minos[j]);
    }
}

int minos_length(minos_t *minos)
{
    int i = 0;

    while (minos) {
        ++i;
        minos = minos->next;
    }
    return (i);
}

minos_t **adapt_minos(minos_t *minos)
{
    minos_t **ret;
    int length;

    if (minos == NULL)
        return (NULL);
    length = minos_length(minos);
    if (!(ret = malloc(sizeof(minos_t *) * (length + 1))))
        return (NULL);
    for (int i = 0; i < length; ++i) {
        ret[i] = minos;
        minos = minos->next;
    }
    ret[length] = NULL;
    sort_minos(ret);
    return (ret);
}
