/*
** EPITECH PROJECT, 2020
** adapt flags
** File description:
** adapt flags to options_t
*/

#include "my.h"
#include "tetris.h"

void adapt_flags(options_t *options, int flags_tab[11])
{
    if (options == NULL)
        return;
    options->level = flags_tab[0];
    for (int i = 0; i < 6; ++i) {
        options->binds[i] = flags_tab[i + 1];
    }
    options->no_next = flags_tab[7];
    options->debug = flags_tab[8];
    options->dim.x = flags_tab[9];
    options->dim.y = flags_tab[10];
}