/*
** EPITECH PROJECT, 2020
** print_minos
** File description:
** prints all pieces
*/

#include "my.h"
#include "minos.h"

static int line_length(char *line)
{
    int ret = 0;

    if (!line)
        return (0);
    while (*line) {
        ++ret;
        ++line;
    }
    --line;
    while (*line == ' ') {
        --ret;
        --line;
    }
    return (ret);
}

static void print_line(char *line)
{
    int len = line_length(line);
    int i = 0;

    while (i < len) {
        write (1, &line[i], 1);
        i += 2;
    }
}

static void adapt_print_minos(char **minos)
{
    for (int i = 0; minos[i]; ++i) {
        print_line(minos[i]);
        my_putchar(1, '\n');
    }
}

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
            adapt_print_minos(minos[i]->minos);
        } else
            my_putstr(1, "Error\n");
    }
}
