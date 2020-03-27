/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define ELEMENT game->element
#define MINOS option->minos
#define MAP game->game_arr
#define ODIM option->dim
#define MINOS_ALEA_Y MINOS[tetriminos_alea]->height
#define MINOS_ALEA_X ((MINOS[tetriminos_alea]->width * 2) - 1)

#endif /* !DEFINE_H_ */