/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_next_minos
*/

#include <ncurses.h>
#include "my.h"
#include "define.h"
#include "minos.h"
#include "library/_string/include/string.h"
#include <time.h>

void process_next_minos(root_t *root, char ***next_tab)
{
    add_to_map(GAME, root->option, GAME_CURRENT);
    multi_free("2", *next_tab);
    destroy_minos(GAME_CURRENT);
    GAME_CURRENT = GAME->next;
    GAME->next = get_random(root->option->minos);
    *next_tab = create_next_tab(GAME->next);
    GAME_CURRENT->current = false;
}