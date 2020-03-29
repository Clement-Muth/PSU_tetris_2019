/*
** EPITECH PROJECT, 2020
** checker
** File description:
** checks if the file is correct
*/

#include "my.h"
#include "minos.h"

static int get_number(char **fline, char *_int)
{
    *_int = (char)my_atoie(*fline);
    if (_int == 0)
        return (1);
    while (**fline && ISNUM(**fline))
        ++*fline;
    ++*fline;
    return (0);
}

static int get_numbers(char *fline, minos_t *minos)
{
    if (fline == NULL)
        return (1);
    if (get_number(&fline, &minos->width) ||
        get_number(&fline, &minos->height))
        return (1);
    minos->color = (char)my_atoie(fline);
    if (minos->color == 0)
        return (1);
    while (ISNUM(*fline))
        ++fline;
    if (*fline)
        return (1);
    return (0);
}

static int is_correct(char *line)
{
    while (*line) {
        if (*line != '*' && *line != ' ')
            return (1);
        ++line;
    }
    return (0);
}

static int check_minos(char **minos, char width)
{
    int asterisks = 0;

    while (*minos) {
        asterisks = count_asterisk(*minos);
        if (asterisks > width ||
            asterisks <= 0 ||
            is_correct(*minos))
            return (1);
        ++minos;
    }
    return (0);
}

int check_file(char **file, minos_t *minos)
{
    if (get_numbers(*file, minos) ||
        my_char2len(file + 1) != minos->height ||
        check_minos(file + 1, minos->width))
        return (1);
    return  (0);
}
