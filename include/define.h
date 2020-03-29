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
#define GAME_NEXT GAME->next
#define ODIM root->option->dim
#define ELEMENT GAME->element
#define MAP GAME->game_arr
#define R_BINDS root->option->binds

#define DOWN GAME_CURRENT->pos.y + i
#define CUR_POS GAME_CURRENT->pos.x + n
#define LEFT CUR_POS - 1
#define RIGHT CUR_POS + 1
#define MINOS_COLL minos->minos[i][n] == '*'
#define CURRENT_RIGHT GAME_CURRENT->minos[i][n] == '*'
#define NB_ELEMENT 2
#define MAP_POSITION_LEFT 35
#define SECOND 1000000
#define RATIO_TIME ((100 - (OPT->level * 10)) * SECOND) / 200
#define MAP_WIDTH j + MAP_POSITION_LEFT + 2 + (map_width * 2)
#define MINOS_ALEA_Y MINOS[tetriminos_alea]->height
#define MINOS_ALEA_X ((MINOS[tetriminos_alea]->width * 2) - 1)
#define TRBINDS(x) my_translate(options->binds[x], &good)

#define RIGHT_HAS_COLLISION CURRENT_RIGHT && (MAP[GAME_CURRENT->pos.y + i][GAME_CURRENT->pos.x \
        + n + 1] == '|' || MAP[GAME_CURRENT->pos.y + i] \
        [GAME_CURRENT->pos.x + n + 2] == '*')

#define LEFT_HAS_COLLISION CURRENT_RIGHT && (MAP[GAME_CURRENT->pos.y + i][GAME_CURRENT->pos.x + n - 1] \
        == '|' || MAP[GAME_CURRENT->pos.y + i] \
        [GAME_CURRENT->pos.x + n - 2] == '*')

#define IS_IN(x) (x < (ODIM.x * 2))

#define CANT_ROTATE IS_IN(GAME_CURRENT->pos.x + GAME_CURRENT->height * 2 + 1) \
        && GAME_CURRENT->collision.right == false \
        && (MAP[GAME_CURRENT->pos.y + i][GAME_CURRENT->pos.x \
        + GAME_CURRENT->height * 2] == '|' || MAP[GAME_CURRENT->pos.y + i] \
        [GAME_CURRENT->pos.x + GAME_CURRENT->height * 2 + 1] == '*')

#endif /* !DEFINE_H_ */