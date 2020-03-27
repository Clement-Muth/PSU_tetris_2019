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

static void
init_tetriminos(game_t *game)
{
    game->element.tetriminos = malloc(sizeof(char *) * 3);
    game->element.tetriminos[0] = "tetriminos/1.tetriminos";
    game->element.tetriminos[1] = "tetriminos/2.tetriminos";
    game->element.tetriminos[2] = "tetriminos/3.tetriminos";
}

void
display_tetriminos(game_t *game)
{
    int tetriminos_alea = rand() % 3;
    char *lineptr = NULL;
    size_t nread = 500;
    FILE *stream;

    init_tetriminos(game);
    stream = fopen(ELEMENT.tetriminos[tetriminos_alea], "r");
    getline(&lineptr, &nread, stream);
    for (int i = 0; lineptr[i]; i++)
        mvaddch(30, 30, lineptr[i]);
}