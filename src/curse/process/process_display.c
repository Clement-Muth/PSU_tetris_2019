/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_display
*/

#include <ncurses.h>
#include "my.h"
#include "define.h"
#include "minos.h"
#include "library/_string/include/string.h"

void process_display(root_t *root, char **next_tab)
{
    for (int i = 0; i != NB_ELEMENT; i++)
        print_game_elements(ELEMENT.filepath[i], ELEMENT.position[i]);
    if (!OPT->no_next) print_next(next_tab, ODIM.x);
    display_map(root);
    display_tetriminos(GAME_CURRENT);
    mvprintw(10, 10, "%d", GAME->score);
    mvprintw(12, 10, "%d", GAME->lines);
    mvprintw(13, 10, "%d", OPT->level);
    print_time(&GAME->timerclock, (vector2_t){19, 15});
}