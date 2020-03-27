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
<<<<<<< HEAD
    init_curse(&game);
    process_curse(&game);
    close_curse();
=======
    my_put2str(1, options->minos[0]->minos);
    multi_free("2", create_next_tab(options->minos[0]));
    /* init_curse(); */
    /* process_curse(); */
    /* close_curse(); */
>>>>>>> 6f9fe84807b7682c1b5a0fb189a7be7c2a8c6bcb
    free_options(options);
    return (0);
}
