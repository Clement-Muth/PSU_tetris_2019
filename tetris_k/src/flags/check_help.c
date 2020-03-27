/*
** EPITECH PROJECT, 2020
** check_help
** File description:
** checks for the hel flag
*/

#include "../../include/my.h"
#include "../../lib/_open/include/openf.h"

static void print_help(void)
{
    openf_readf("data/describe.txt");
}

int is_help(char **av)
{
    while (*av) {
        if (my_strcomp(*av++, "--help")) {
            print_help();
            return (1);
        }
    }
    return (0);
}
