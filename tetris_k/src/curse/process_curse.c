/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_curse
*/

#include <ncurses.h>
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

static void
print_game(char *filepath, vector2_t position, bool mod)
{
    char *lineptr = NULL;
    size_t nread = 500;
    FILE *stream = fopen(filepath, "r");

    for (int i = 0; -1 != getline(&lineptr, &nread, stream); i++)
        for (int n = 0; lineptr[n]; n++)
            mvaddch(i + position.y, n + position.x, lineptr[n]);
}

void
process_curse(void)
{
    bool game = true;
    char c = '\0';
    vector2_t position[] = {{1, 0}, {1, 7}, {31, 0}};
    char *path[] = {"data/title_game.txt", "data/score.txt", "data/game.txt"};
    bool mod[] = {1, 0, 0};

    while (game) {
        clear();
        for (int i = 0; i != 3; i++)
            print_game(path[i], position[i], mod[i]);
        c = getch();
        usleep(1000000);
    }
}