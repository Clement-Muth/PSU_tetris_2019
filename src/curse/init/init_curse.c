/*
** EPITECH PROJECT, 2020
** init_curse
** File description:
** inits and close curse window
*/

#include "my.h"
#include "tetris.h"
#include "struct.h"
#include "library/_string/include/string.h"
#include <time.h>

static void
init_curse_struct(root_t *root)
{
    GAME->in_game = true;
    GAME->timerclock = clock();
    GAME->score = 0;
    ELEMENT.filepath = malloc(sizeof(char *) * 2);
    ELEMENT.filepath[0] = "data/title_game.txt";
    ELEMENT.filepath[1] = "data/score.txt";
    ELEMENT.position = (vector2_t []){{1, 0}, {1, 7}};
    MAP = create_map(root);
    CLOCK.begin = clock();
    CLOCK.ellapsed = clock() - CLOCK.begin;
    CLOCK.level_time_descent = RATIO_TIME;
}

void
init_curse(root_t *root)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    init_curse_struct(root);
}

void close_curse(void)
{
    endwin();
}