/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for the program
*/

#include "my.h"
#include "list.h"
#include "regex.h"
#include "minos.h"
#include "struct.h"
#include "define.h"
#include <time.h>
#include <SFML/Graphics.h>

static void free_root(root_t *root)
{
    if (!root)
        return;
    if (root->option && root->option->minos) {
        for (int i = 0; root->option->minos[i]; ++i) {
            multi_free("21", root->option->minos[i]->minos, root->option->minos[i]->name);
            free(root->option->minos[i]);
        }
        freeif(root->option->minos);
    }
    freeif(root->option);
    freeif(root->game);
}

static int all_right(minos_t **minos)
{
    for (int i = 0; minos[i]; ++i) {
        if (minos[i]->minos == NULL) {
            my_printf(1, "One of the pieces is incorrect\n");
            return (0);
        }
    }
    return (1);
}

static int start(int ac, char **av, root_t *root)
{
    if (is_help(av))
        return (0);
    root->option = init_options(ac, av);
    if (root->option == NULL)
        return (84);
    if (root->option->minos == NULL) {
        my_putstr(1, "No pieces in the minos directory\n");
        return (84);
    }
    else
        if (root->option->debug)
            debug_mode(root->option);
    return (all_right(root->option->minos));
}

int main(int ac, char **av)
{
    root_t root;
    int state = 1;

    root.game = malloc(sizeof(game_t));
    root.option = malloc(sizeof(options_t));
    srand(getpid() * time(NULL));
    if ((state = start(ac, av, &root)) != 1) {
        free_root(&root);
        return (state);
    }
    init_curse(&root);
    process_curse(&root);
    close_curse();
    free_root(&root);
    return (0);
}