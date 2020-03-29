/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_curse
*/

#include "my.h"
#include "tetris.h"
#include "minos.h"
#include "struct.h"
#include "library/_string/include/string.h"

static int process_descent_minos(root_t *root)
{
    CLOCK.begin = clock();
    if (!GAME_CURRENT->collision.down) {
        GAME_CURRENT->pos.y++;
        return (false);
    } else
        return (true);
}

void add_line(game_t *game, options_t *option, minos_t *minos, int i)
{
    for (int j = 0; minos->minos[i][j]; ++j)
        if (minos->minos[i][j] == '*')
            game->game_arr[minos->pos.y + i][minos->pos.x + j] = '*';

}

void add_to_map(game_t *game, options_t *option, minos_t *minos)
{
    for (int i = 0; minos->minos[i]; ++i)
        add_line(game, option, minos, i);
}

void process_curse(root_t *root)
{
    char **next_tab;

    GAME_CURRENT = get_random(OPT->minos);
    GAME_NEXT = get_random(OPT->minos);
    next_tab = create_next_tab(GAME_NEXT);
    while (GAME->in_game) {
        process_display(root, next_tab);
        GAME->lines += check_lines(root);
        CLOCK.ellapsed = clock() - CLOCK.begin;
        if (get_inputs(root)) return;
        process_collisions(root);
        if (CLOCK.ellapsed > CLOCK.level_time_descent)
            GAME_CURRENT->current = process_descent_minos(root);
        if (GAME_CURRENT->current) {
            process_next_minos(root, &next_tab);
            clear();
        }
        refresh();
    }
}