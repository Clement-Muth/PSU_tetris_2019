/*
** EPITECH PROJECT, 2020
** format_piece
** File description:
** formats piece
*/

#include "../../include/my.h"
#include "../../include/minos.h"

static char line_length(char *line)
{
    char ret = 0;

    if (!line)
        return (0);
    while (line[(int)ret]) {
        ++ret;
    }
    while (line[ret - 1] == ' ') {
        --ret;
    }
    return (ret);
}

static char *format_line(char *line)
{
    int len = line_length(line) * 2;
    char *new_line = malloc(len);
    int i = 0;

    if (new_line == NULL)
        return (NULL);
    while (*line) {
        if (i != 0)
            new_line[i++] = ' ';
        new_line[i] = *line++;
        ++i;
    }
    new_line[len - 1] = '\0';
    return (new_line);
}

int format_piece(minos_t *new, char **piece)
{
    if (!(new->minos = malloc(sizeof(char *) * (new->height + 1))))
        return (1);
    for (int i = 0; i < new->height; ++i) {
        if (!(new->minos[i] = format_line(piece[i]))) {
            free_done((void **)new->minos, i);
            return (1);
        }
    }
    new->minos[(int)new->height] = NULL;
    return (0);
}
