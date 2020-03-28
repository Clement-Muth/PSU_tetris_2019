/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_display
*/

#include <ncurses.h>
#include "../../../include/my.h"
#include "../../../include/define.h"
#include "../../../include/minos.h"
#include "../../../lib/_string/include/string.h"

void
process_display(root_t *root, char **next_tab)
{
    for (int i = 0; i != NB_ELEMENT; i++)
        print_game_elements(ELEMENT.filepath[i], ELEMENT.position[i]);
    if (!OPT->no_next) print_next(next_tab, ODIM.x);
    display_map(root);
    display_tetriminos(GAME_CURRENT);
}