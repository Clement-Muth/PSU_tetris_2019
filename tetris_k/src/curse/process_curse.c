/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_curse
*/

#include <ncurses.h>
#include "../../include/define.h"
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

static void
print_game(char *filepath, vector2_t position)
{
    char *lineptr = NULL;
    size_t nread = 500;
    FILE *stream = fopen(filepath, "r");
    char *posx = NULL;
    char *posy = NULL;

    getline(&posy, &nread, stream);
    getline(&posx, &nread, stream);
    for (int i = 0; -1 != getline(&lineptr, &nread, stream); i++)
        for (int n = 0; lineptr[n]; n++)
            mvaddch(i + _atoi(posy), n + _atoi(posx), lineptr[n]);
}

void
process_curse(game_t *game)
{
    while (game) {
        clear();
        for (int i = 0; i != 3; i++)
            print_game(ELEMENT.filepath[i], ELEMENT.position[i]);
        display_tetriminos(game);
        game->catch = getch();
        usleep(1000000);
    }
}