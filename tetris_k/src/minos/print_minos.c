/*
** EPITECH PROJECT, 2020
** print_minos
** File description:
** prints all pieces
*/

#include "../../include/my.h"
#include "../../include/minos.h"

void print_minos(minos_t **minos)
{
    if (!minos)
        return;
    my_printf(1, "Tetriminos :  %d\n", minos_length(*minos));
    for (int i = 0; minos[i]; ++i) {
        my_printf(1, "Tetriminos :  Name %s :  ", minos[i]->name);
        if (minos[i]->minos) {
            my_printf(1, "Size %d*%d :  Color %d\n", minos[i]->width,
                    minos[i]->height, minos[i]->color);
                my_put2str(1, minos[i]->minos);
        } else
            my_putstr(1, "Error\n");
    }
}
