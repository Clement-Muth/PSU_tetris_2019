/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** tetris header file
*/

#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include <time.h>
#include "struct.h"
#include "define.h"

options_t *init_options(int ac, char **av);
int is_help(char **av);

int debug_mode(options_t *options);

int fill_flags(int flags_tab[11], int pos, char *arg);
void adapt_flags(options_t *options, int flags_tab[11]);

void init_curse(root_t *root);
void display_map(root_t *root);
void process_curse(root_t *root);
void close_curse(void);

void display_tetriminos(minos_t *minos);
void print_game_elements(char *filepath, vector2_t position);
void print_next(char **next, int map_width);
void print_time(clock_t *clock, vector2_t pos);

void add_to_map(game_t *game, options_t *option, minos_t *minos);

char **create_map(root_t *root);

minos_t *get_random(minos_t **minos);

minos_t *read_minos(char *directory, vector2_t dim);

int check_lines(root_t *root);
int get_inputs(root_t *root);

/*          Process_display         */
void process_display(root_t *root, char **next_tab);
void process_next_minos(root_t *root, char **next_tab);

#endif
