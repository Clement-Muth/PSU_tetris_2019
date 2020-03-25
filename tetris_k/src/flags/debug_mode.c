/*
** EPITECH PROJECT, 2020
** debug_mode
** File description:
** debug mode for tetris
*/

#include "../../include/my.h"
#include "../../include/minos.h"
#define BINDS options->binds

int debug_mode(options_t *options)
{
    my_putstr (1, "*** DEBUG MODE ***\n");
    my_printf (1, "Key Left :    |%c %d|\n", BINDS[0], BINDS[0]);
    my_printf (1, "Key Right :    |%c %d|\n", BINDS[1], BINDS[1]);
    my_printf (1, "Key Turn :    |%c %d|\n", BINDS[2], BINDS[2]);
    my_printf (1, "Key Drop :    |%c %d|\n", BINDS[3], BINDS[3]);
    my_printf (1, "Key Quit :    |%c %d|\n", BINDS[4], BINDS[4]);
    my_printf (1, "Key Pause :    |%c %d|\n", BINDS[5], BINDS[4]);
    my_printf (1, "Next :    %s\n", (options->no_next ? "No": "Yes"));
    my_printf(1, "Level :    %d\n", options->level);
    my_printf (1, "dim :    %d*%d\n", options->dim.x, options->dim.y);
    print_minos(options->minos);
    my_putstr(1, "wait key press\n");
    return (0);
}
