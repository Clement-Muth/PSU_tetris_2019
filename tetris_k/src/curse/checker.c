/*
** EPITECH PROJECT, 2020
** checker
** File description:
** checker
*/

#include "../../include/define.h"
#include "../../include/minos.h"
#include "../../lib/_string/include/string.h"

int
is_filled(char *line)
{
    int width = ODIM.x * 2;

    for (int i = 0; i < width; i += 2) {

    }
}

int
check_lines(game_t *game, options_t *option, minos_t *minos)
{
    int down = ODIM.y - 1;

    while (down) {
        while (is_filled(game->game_arr[down]))
            destroy_line(game->game_arr, down);
    }
    return (0);
}
