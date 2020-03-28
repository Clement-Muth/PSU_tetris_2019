/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** display_tetriminos
*/

#include <ncurses.h>
#include "../../include/define.h"
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

void
display_map(game_t *game, options_t *option)
{
    int beaucoup = ODIM.y;
    int un_peu_moins = ODIM.x;

    for (int i = 0; beaucoup != i; i++)
        for (int n = 0; un_peu_moins != n; n++)
            mvaddch(i + 1, n + 36, MAP[i][n]);
}

minos_t *
cpy_minos(minos_t *minos)
{
   minos_t *ret = malloc(sizeof(minos_t));

    if (!ret)
        return (ret);
    ret->minos = my_char2dup(minos->minos);
    ret->name = my_strdup(minos->name);
    ret->width = minos->width;
    ret->height = minos->height;
    ret->pos = minos->pos;
    return (ret);
}

minos_t *
get_random(minos_t **minos)
{
    int mrand = rand() % minos_length(minos);

    return (cpy_minos(minos[mrand]));
}

void
display_tetriminos(game_t *game, options_t *option)
{
    int tetriminos_alea = rand() % 1;
    minos_t *actual = get_random(option->minos);

    // for (int i = 0; MINOS_ALEA_Y != i; i++)
    //     for (int n = 0; MINOS_ALEA_X != n; n++) {
    //         MAP[MINOS[tetriminos_alea]->pos.y + i][n]
    //         = MINOS[tetriminos_alea]->minos[i][n];
    //     }
    // for (int i = 0; ODIM.y != i; i++)
    //     for (int n = 0; ODIM.x != n; n++)
    //         mvaddch(i + 1, n + 36, MAP[i][n]);
    usleep(1000);
    for (int i = 0; actual->minos[i]; i++)
        for (int n = 0; actual->minos[i][n]; n++)
            mvaddch(actual->pos.y + 1, n + 36, actual->minos[i][n]);
}