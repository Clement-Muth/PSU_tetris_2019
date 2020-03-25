/*
** EPITECH PROJECT, 2020
** format_piece
** File description:
** formats piece
*/

#include "../../include/my.h"
#include "../../include/minos.h"

static char *format_line(char asterisks)
{
    int i = 0;
    char *new_line = malloc(asterisks * 2);

    if (new_line == NULL)
        return (NULL);
    while (asterisks) {
        new_line[i++] = '*';
        if (--asterisks)
            new_line[i++] = ' ';
    }
    new_line[i] = '\0';
    return (new_line);
}

static void free_done(char **to_free, int done)
{
    --done;
    while (done != -1) {
        free(to_free[done--]);
    }
}

int format_piece(minos_t *new, char **piece)
{
    if (!(new->minos = malloc(sizeof(char *) * (new->height + 1))))
        return (1);
    for (int i = 0; i < new->height; ++i) {
        if (!(new->minos[i] = format_line((char)count_asterisk(piece[i])))) {
            free_done(new->minos, i);
            return (1);
        }
    }
    new->minos[(int)new->height] = NULL;
    return (0);
}
