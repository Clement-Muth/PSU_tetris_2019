/*
** EPITECH PROJECT, 2020
** fill_minos
** File description:
** fill linked list
*/

#include "my.h"
#include "minos.h"

static void add_minos(minos_t **minos, char *filename, vector2_t dim)
{
    char **file = get_file(my_glue_sep("tetriminos", filename, '/'));
    minos_t *new;

    if (!file || (!(new = malloc(sizeof(minos_t))))) {
        multi_free("2", file);
        return;
    }
    if (check_file(file, new) ||
        format_piece(new, file + 1)) {
        new->minos = NULL;
    }
    new->name = my_strndup(filename, my_strfind(filename, ".tetrimino"));
    new->next = *minos;
    new->pos.x = ((dim.x) - (new->width + 1));
    new->pos.x += (!(new->pos.x & 1));
    new->pos.y = 1;
    new->collision = (collision_t){false, false, false};
    new->current = false;
    *minos = new;
    multi_free("2", file);
}

static int is_ext(char *str, char *ext)
{
    while (*str != '.') {
        if (*str == '\0')
            return (0);
        ++str;
    }
    while (*str) {
        if (*str != *ext++)
            return (0);
        ++str;
    }
    return (*str == '\0' && *ext == '\0');
}

int fill_minos(minos_t **minos, char *name, vector2_t dim)
{
    if (is_ext(name, ".tetrimino")) add_minos(minos, name, dim);
    return (0);
}
