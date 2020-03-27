/*
** EPITECH PROJECT, 2020
** format_piece
** File description:
** formats piece
*/

#include "../../include/my.h"
#include "../../include/minos.h"

static char *format_line(char *line, int width)
{
    char *new_line = malloc(width);
    int i = 0;

    if (new_line == NULL)
        return (NULL);
    while (*line) {
        if (i != 0)
            new_line[i++] = ' ';
        new_line[i] = *line++;
        ++i;
    }
    while (i < width) {
        new_line[i] = ' ';
        ++i;
    }
    new_line[width - 1] = '\0';
    return (new_line);
}

int format_piece(minos_t *new, char **piece)
{
    if (!(new->minos = malloc(sizeof(char *) * (new->height + 1))))
        return (1);
    for (int i = 0; i < new->height; ++i) {
        if (!(new->minos[i] = format_line(piece[i], new->width * 2))) {
            free_done((void **)new->minos, i);
            return (1);
        }
    }
    new->minos[(int)new->height] = NULL;
    return (0);
}
