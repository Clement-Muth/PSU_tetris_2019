/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main for the program
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/regex.h"
#include "../include/minos.h"
#include "../include/struct.h"
#include "../include/define.h"
#include <time.h>

void free_options(options_t *options)
{
    if (options->minos)
        for (int i = 0; options->minos[i]; ++i) {
            multi_free("21", options->minos[i]->minos, options->minos[i]->name);
            free(options->minos[i]);
        }
    freeif(options->minos);
    freeif(options);
}

int main(int ac, char **av)
{
    root_t root;

    root.game = malloc(sizeof(game_t));
    root.option = malloc(sizeof(options_t));
    srand(getpid() * time(NULL));
    if (is_help(av))
        return (0);
    root.option = init_options(ac, av);
    if (root.option == NULL)
        return (84);
    if (root.option->minos == NULL)
        printf("minos == NULL\n");
    else
        if (root.option->debug)
            debug_mode(root.option);
    init_curse(&root);
    process_curse(&root);
    close_curse();
    free_options(root.option);
    return (0);
}
