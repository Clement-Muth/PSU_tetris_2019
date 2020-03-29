/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_collisions
*/

#include "my.h"
#include "minos.h"
#include "tetris.h"
#include "library/_string/include/string.h"

static void set_collisions(root_t *root, int i)
{
    for (int n = 0; GAME_CURRENT->minos[i][n]; n++) {
        if (CURRENT_RIGHT && MAP[DOWN + 1][CUR_POS] != ' ')
            GAME_CURRENT->collision.down = true;
        if (CURRENT_RIGHT && (MAP[DOWN][LEFT] == '|' || MAP[DOWN][LEFT + 1] == '*'))
            GAME_CURRENT->collision.left = true;
        if (CURRENT_RIGHT && (MAP[DOWN][RIGHT] == '|' || MAP[DOWN][LEFT + 1] == '*'))
            GAME_CURRENT->collision.right = true;
    }
}

void process_collisions(root_t *root)
{
    GAME_CURRENT->collision = (collision_t){0, 0, 0};
    for (int i = 0; GAME_CURRENT->minos[i]; i++) {
        set_collisions(root, i);
    }
}