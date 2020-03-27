/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** display_tetriminos
*/

#include <ncurses.h>
#include "../../include/define.h"
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

void
display_tetriminos(game_t *game, options_t *option)
{
    int tetriminos_alea = 0;

    // printf("%d::%d::%d\n", MINOS_ALEA_Y, MINOS_ALEA_X, MINOS[tetriminos_alea]->width);
    for (int i = 0; MINOS_ALEA_Y != i; i++)
        for (int n = 0; MINOS_ALEA_X != n; n++) {
            MAP[i][n] = MINOS[tetriminos_alea]->minos[i][n];
        }
    for (int i = 0; MINOS_ALEA_Y; i++)
        for (int n = 0; MINOS_ALEA_X; n++)
            mvaddch(i + 10, n + 40, MAP[i][n]);
    exit(0);
}