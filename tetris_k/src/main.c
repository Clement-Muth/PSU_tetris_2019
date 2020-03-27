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
    options_t *options;
    game_t game;

    srand(getpid() * time(NULL));
    if (is_help(av))
        return (0);
    options = init_options(ac, av);
    if (options == NULL)
        return (84);
    if (options->minos == NULL)
        printf("minos == NULL\n");
    else
        if (options->debug)
            debug_mode(options);
    init_curse(&game);
    process_curse(&game);
    close_curse();
    free_options(options);
    return (0);
}
