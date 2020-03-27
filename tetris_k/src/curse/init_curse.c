/*
** EPITECH PROJECT, 2020
** init_curse
** File description:
** inits and close curse window
*/

#include "../../include/define.h"
#include "../../include/my.h"
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

static void init_curse_struct(game_t *game, options_t *option)
{
    int i = 0;

    game->in_game = true;
    game->catch = '\0';
    ELEMENT.filepath = malloc(sizeof(char *) * 3);
    ELEMENT.filepath[0] = "data/title_game.txt";
    ELEMENT.filepath[1] = "data/score.txt";
    ELEMENT.filepath[2] = "data/game.txt";
    ELEMENT.position = (vector2_t []){{1, 0}, {1, 7}, {31, 0}};
    MAP = malloc(sizeof(char *) * ODIM.y);
    for (i = 0; ODIM.y != i; i++) MAP[i] = _memalloc(MAP[i], ODIM.x);
}

void init_curse(game_t *game, options_t *option)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    echo();
    init_curse_struct(game, option);
}

void close_curse(void)
{
    endwin();
}