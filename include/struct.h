/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

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
    bool current;
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

typedef struct _clock_s
{
    clock_t begin;
    clock_t ellapsed;
    int level_time_descent;
} _clock_t;


typedef struct game_s
{
    bool in_game;
    char **game_arr;
    clock_t timerclock;
    minos_t *cur;
    minos_t *next;
    _clock_t clock;
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

typedef struct root_s
{
    game_t *game;
    options_t *option;
} root_t;

#endif /* !STRUCT_H_ */