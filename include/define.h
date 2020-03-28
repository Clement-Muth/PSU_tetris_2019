/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Debian]
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define MINOS option->minos
#define COLLISION minos->collision
#define GAME root->game
#define OPT root->option
#define CLOCK GAME->clock
#define GAME_CURRENT GAME->cur
#define ODIM root->option->dim
#define ELEMENT GAME->element
#define MAP GAME->game_arr

#define NB_ELEMENT 2
#define MAP_POSITION_LEFT 35
#define SECOND 1000000
#define RATIO_TIME ((100 - (OPT->level * 10)) * SECOND) / 100
#define MAP_WIDTH j + MAP_POSITION_LEFT + 2 + (map_width * 2)
#define MINOS_ALEA_Y MINOS[tetriminos_alea]->height
#define MINOS_ALEA_X ((MINOS[tetriminos_alea]->width * 2) - 1)

#endif /* !DEFINE_H_ */