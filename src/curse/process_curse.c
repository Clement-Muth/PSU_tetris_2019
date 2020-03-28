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
    if (game->game_arr[minos->pos.y + minos->height][minos->pos.x] != ' ') {
        mvprintw(0, 0, "touched !!\n");
        minos->collision.down = true;
    } else
        minos->collision.down = false;
}

static int
process_descent_minos(game_t *game, minos_t *minos)
{
    minos->pos.y++;
    check_collision(game, minos);
    return (COLLISION.down) ? (true) : (false);
}

void
add_to_map(game_t *game, options_t *option, minos_t *minos)
{
    int y_max = minos->pos.y + minos->height;
    int x_max = minos->pos.x + minos->width * 2;

    for (int i = minos->pos.y; i < y_max;++i)
        for (int j = minos->pos.x; j < x_max; ++j)
            game->game_arr[i][j] = (minos->minos[i - minos->pos.y][j - minos->pos.x] != ' ') ?
                ('*') : (game->game_arr[i][j]);
}

void
process_curse(root_t *root)
{
    char **next_tab;

    GAME_CURRENT = get_random(OPT->minos);
    GAME->next = get_random(OPT->minos);
    next_tab = create_next_tab(GAME->next);
    while (GAME->in_game) {
        process_display(root, next_tab);
        if (CLOCK.ellapsed > CLOCK.level_time_descent) {
            GAME_CURRENT->current = process_descent_minos(GAME, GAME_CURRENT);
            CLOCK.begin = clock();
        }
        if (GAME_CURRENT->current) {
            process_next_minos(root, next_tab);
            clear();
        }
        refresh();
    }
}
