/*
** EPITECH PROJECT, 2020
** fill_flags.c
** File description:
** fill tetris flags
*/

#include "../../include/my.h"
#include "../../include/regex.h"

static int choose_level(int flags_tab[11], char *arg)
{
    int level = 0;

    if (my_str_isnum(arg) == 1 || (level = my_atoi(arg)) < 0) {
        my_putstr (2, "Error: level must only be absolute numbers\n");
        return (1);
    }
    flags_tab[0] = level;
    return (0);
}

static int choose_bind(int flags_tab[11], int pos, char *arg)
{
    if (my_strlen(arg) != 1) {
        my_putstr(2, "Error: bindings must only be characters\n");
        return (1);
    }
    flags_tab[pos] = *arg;
    return (0);
}

static int read_dim(int flags_tab[11], char *arg)
{
    regex_t regex = create_regex("[0-9],[0-9]");
    int index = 0;

    if (check_regex(arg, &regex) == 0) {
       destroy_regex(&regex);
       return (1);
    }
    destroy_regex(&regex);
    flags_tab[9] = my_atoie(arg);
    while (arg[index] != ',' && arg[index])
        ++index;
    if (arg[index] == '\0')
        return (1);
    flags_tab[10] = my_atoie(arg + index + 1);
    if (flags_tab[9] <= 0 || flags_tab[10] <= 0) {
        return (1);
    }
    return (0);
}

int fill_flags(int flags_tab[11], int pos, char *arg)
{
    switch (pos) {
    case 0:
        if (choose_level(flags_tab, arg))
            return (1);
        break;
    case 1 ... 6:
        if (choose_bind(flags_tab, pos, arg))
           return (1);
        break;
    case 7 ... 8:
        flags_tab[pos] = 1;
        break;
    case 9:
        if (read_dim(flags_tab, arg)) {
            my_putstr(2, "Error: dimensions are incorrects\n");
            return (1);
        }
        break;
    }
    return (0);
}
