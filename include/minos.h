/*
** EPITECH PROJECT, 2020
** minos
** File description:
** minos header
*/

#ifndef __MINOS_H_
#define __MINOS_H_

#include "tetris.h"

minos_t **adapt_minos(minos_t *minos);
int minos_length(minos_t *minos);
void print_minos(minos_t **minos);
int fill_minos(minos_t **minos, char *name, vector2_t dim);
char **get_file(char *filename);
int format_piece(minos_t *new, char **piece);
int count_asterisk(char *line);
int check_file(char **file, minos_t *minos);
minos_t *read_minos(char *directory, vector2_t dim);
char **create_next_tab(minos_t *minos);
void destroy_minos(minos_t *minos);
int rotate_minos(minos_t *minos);

#endif // __MINOS_H_
