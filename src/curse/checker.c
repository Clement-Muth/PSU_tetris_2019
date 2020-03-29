/*
** EPITECH PROJECT, 2020
** checker
** File description:
** checker
*/

#include "../../include/define.h"
#include "../../include/minos.h"
#include "../../lib/_string/include/string.h"

static void
destroy_line(char **map, int line)
{
    while (line) {
        for (int i = 0; map[line][i]; ++i)
            map[line][i] = (line != 1) ? (map[line - 1][i]) : ' ';
        --line;
    }
}

static bool
is_filled(root_t *root, char *line)
{
    int ret = 0;

    for (int i = 0; line[i]; ++i)
        ret += (line[i] == '*');
    return (ret == ODIM.x);
}

int
check_lines(root_t *root)
{
    int down = ODIM.y - 2;

    while (down) {
        while (is_filled(root, GAME->game_arr[down]))
            destroy_line(GAME->game_arr, down);
        --down;
    }
    return (0);
}
