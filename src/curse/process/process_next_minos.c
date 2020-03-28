/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** process_next_minos
*/

#include <ncurses.h>
#include "../../../include/my.h"
#include "../../../include/define.h"
#include "../../../include/minos.h"
#include "../../../lib/_string/include/string.h"
#include <time.h>

void
process_next_minos(root_t *root, char **next_tab)
{
    add_to_map(GAME, root->option, GAME_CURRENT);
    freeif_2d((void **)next_tab);
    destroy_minos(GAME_CURRENT);
    GAME_CURRENT = GAME->next;
    GAME->next = get_random(root->option->minos);
    next_tab = create_next_tab(GAME->next);
    GAME_CURRENT->current = false;
}