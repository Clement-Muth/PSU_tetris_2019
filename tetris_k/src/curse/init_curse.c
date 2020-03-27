/*
** EPITECH PROJECT, 2020
** init_curse
** File description:
** inits and close curse window
*/

#include "../../include/my.h"
#include "../../include/tetris.h"

static void init_curse_struct(game_t *game)
{
    game->in_game = true;
    game->catch = '\0';
    game->element.filepath = malloc(sizeof(char *) * 3);
    game->element.filepath[0] = "data/title_game.txt";
    game->element.filepath[1] = "data/score.txt";
    game->element.filepath[2] = "data/game.txt";
    game->game_arr = malloc(sizeof(char *) * 30);
    game->element.position = (vector2_t []){{1, 0}, {1, 7}, {31, 0}};
}

void init_curse(game_t *game)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    echo();
    init_curse_struct(game);
}

void close_curse(void)
{
    endwin();
}