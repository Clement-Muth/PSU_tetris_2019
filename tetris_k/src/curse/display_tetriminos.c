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
    int tetriminos_alea = rand() % 2;

    for (int i = 0; (MINOS[tetriminos_alea]->height * 2) != i; i++) {
        for (int n = 0; (MINOS[tetriminos_alea]->width * 2) != n; n++)
            MAP[i][n] = MINOS[tetriminos_alea]->minos[i][n];
    }
    for (int i = 0; (MINOS[tetriminos_alea]->height * 2) != i; i++)
        for (int n = 0; (MINOS[tetriminos_alea]->width * 2) != n; n++)
            mvaddch(i + 10, n + 40, MAP[i][n]);
}