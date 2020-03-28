/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_curse
*/

#include <ncurses.h>
#include "../../include/my.h"
#include "../../include/define.h"
#include "../../include/minos.h"
#include "../../lib/_string/include/string.h"
#include <time.h>

static void
check_collision(game_t *game, minos_t *minos)
{
    if (game->game_arr[minos->pos.y + minos->height + 1][minos->pos.x] != ' ')
        minos->collision.down = true;
}

static int
process_current_minos(game_t *game, minos_t *minos)
{
    return (0);
}

static int
process_descent_minos(game_t *game, minos_t *minos)
{
    ++minos->pos.y;
    check_collision(game, minos);
    return (COLLISION.down) ? (1) : (0);
}

void
process_curse(game_t *game, options_t *option)
{
    minos_t *current = get_random(option->minos);
    minos_t *next = get_random(option->minos);
    char **next_tab = create_next_tab(next);
    clock_t begin = clock();
    clock_t ellapsed = 0;
    int level_time_descent = RATIO_TIME;

    while (game) {
        ellapsed = clock() - begin;
        for (int i = 0; i != NB_ELEMENT; i++)
            print_game_elements(ELEMENT.filepath[i], ELEMENT.position[i]);
        if (!option->no_next) print_next(next_tab, ODIM.x);
        display_map(game, option);
        display_tetriminos(game, option, current);
        if (ellapsed > level_time_descent) {
            process_descent_minos(game, current);
            begin = clock();
        }
        if (process_current_minos(game, current)) {
            freeif_2d((void **)next_tab);
            destroy_minos(current);
            current = next;
            next = get_random(option->minos);
            next_tab = create_next_tab(next);
        }
        refresh();
    }
}
