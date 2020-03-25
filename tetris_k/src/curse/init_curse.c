/*
** EPITECH PROJECT, 2020
** init_curse
** File description:
** inits and close curse window
*/

#include "../../include/my.h"
#include "../../include/tetris.h"


void init_curse(void)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    echo();
}

void close_curse(void)
{
    endwin();
}
