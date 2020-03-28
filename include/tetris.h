/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** tetris header file
*/

#ifndef TETRIS_H
#define TETRIS_H

typedef struct vector2_s
{
    int x;
    int y;
} vector2_t;

typedef struct collision_s
{
    bool left;
    bool right;
    bool down;
} collision_t;


typedef struct minos_s
{
    char **minos;
    char *name;
    char width;
    char height;
    char color;
    vector2_t pos;
    collision_t collision;
    struct minos_s *next;
} minos_t;

typedef struct element_s
{
    char **filepath;
    char **tetriminos;
    vector2_t *position;
} element_t;


typedef struct game_s
{
    bool in_game;
    char catch;
    char **game_arr;
    element_t element;
} game_t;

typedef struct options_s
{
    minos_t **minos;
    int binds[6];
    vector2_t dim;
    unsigned short int level;
    char no_next;
    char debug;
} options_t;

options_t *init_options(int ac, char **av);
int is_help(char **av);

int debug_mode(options_t *options);

int fill_flags(int flags_tab[11], int pos, char *arg);
void adapt_flags(options_t *options, int flags_tab[11]);

void init_curse(game_t *game, options_t *option);
void display_map(game_t *game, options_t *option);
void process_curse(game_t *game, options_t *option);
void close_curse(void);

void display_tetriminos(game_t *game, options_t *option, minos_t *minos);
void print_game_elements(char *filepath, vector2_t position);
void print_next(char **next, int map_width);

char **create_map(options_t *option);

minos_t *get_random(minos_t **minos);

minos_t *read_minos(char *directory, vector2_t dim);

#endif
