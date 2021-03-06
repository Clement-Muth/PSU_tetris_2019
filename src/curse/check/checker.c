/*
** EPITECH PROJECT, 2020
** checker
** File description:
** checker
*/

#include "define.h"
#include "minos.h"
#include "library/_string/include/string.h"

static void
destroy_line(char **map, int line)
{
    while (line) {
        for (int i = 1; map[line][i] && map[line][i] != '|'; ++i)
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
    return (ret == ODIM.x - 1);
}

int
check_lines(root_t *root)
{
    int down = ODIM.y;
    int line = 0;
    int score_ptn[] = {40, 100, 300, 1200};

    while (down) {
        while (is_filled(root, GAME->game_arr[down])) {
            destroy_line(GAME->game_arr, down);
            line += 1;
        }
        --down;
    }
    if (0 != line)
        root->game->score += (line < 4) ? (score_ptn[line]) : (1200);

    return (line);
}
