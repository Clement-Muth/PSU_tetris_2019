/*
** EPITECH PROJECT, 2020
** read_flags
** File description:
** read tetris flags
*/

#include "../../include/my.h"
#include "../../include/regex.h"
#include "../../include/minos.h"
#include <getopt.h>

static int find_pos(char _char, char *str)
{
    for (int i = 0; str[i]; ++i)
        if (_char == str[i])
            return (i);
    return (-1);
}

static int read_flags(int flags_tab[11], struct option long_options[],
                int ac, char **av)
{
    int opt;
    char *flags = "LlrtdqpwD";
    int pos = 0;
    int index = 0;

    while ((opt = getopt_long(ac, av, "L:l:r:t:d:q:p:wD",
        long_options, &index)) != -1) {
        if (opt == '?')
            return (84);
        pos = find_pos(opt, flags);
        if (opt == 0) {
            fill_flags(flags_tab, index, optarg);
        } else if (fill_flags(flags_tab, pos, optarg))
            return (84);
    }
    return (0);
}

options_t *init_options(int ac, char **av)
{
    options_t *options = malloc(sizeof(options_t));
    int flags_tab[11] = {0, 'q', 'd', 'a', 's', 'l', 'p', 0, 0, 10, 20};
    struct option long_options[] = {
        {"level", 1, 0, 0}, {"key-left", 1, 0, 0},
        {"key-right", 1, 0, 0}, {"key-turn", 1, 0, 0},
        {"key-drop", 1, 0, 0}, {"key-quit", 1, 0, 0},
        {"key-pause", 1, 0, 0}, {"without-next", 0, 0, 0},
        {"debug", 0, 0, 0}, {"map-size", 1, 0, 0},
        {0, 0, 0, 0}
    };

    if (options == NULL)
        return (NULL);
    read_flags(flags_tab, long_options,  ac, av);
    adapt_flags(options, flags_tab);
    options->minos = adapt_minos(read_minos("tetriminos", options->dim));
    return (options);
}
