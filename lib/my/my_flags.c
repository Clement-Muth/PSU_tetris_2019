/*
** EPITECH PROJECT, 2020
** flags
** File description:
** handles flags
*/

#include "my.h"

static int checker(char *str, char **flags)
{
    for (int i = 0; i < FLAGS_COL && flags[i]; ++i)
        if (my_strcomp(str, flags[i]) == 1)
            return (1);
    return (0);
}

int is_flag(char *str, char *flags[FLAGS_LINES][FLAGS_COL])
{
    if (my_str_isnum(str) == 0)
        return (0);
    for (int ret = 0; ret < FLAGS_LINES; ++ret) {
        if (checker(str, flags[ret]) == 1)
            return (ret + 1);
    }
    return (-1);
}

static int single_checker(char _char, char *flags)
{
    printf ("checking %c with %s\n", _char, flags);
    for (int i = 0; flags[i]; ++i) {
        if (flags[i] == _char)
            return (1);
    }
    return (0);
}

int is_single(char _char, char *flags[FLAGS_LINES])
{
    int ret = 0;

    while (ret < FLAGS_LINES) {
        if (single_checker(_char, flags[ret]) == 1)
            return (ret + 1);
        ++ret;
    }
    return (-1);
}
