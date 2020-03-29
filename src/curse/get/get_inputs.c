/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** gets inputs
*/

#include "my.h"
#include "define.h"
#include "minos.h"
#include "library/_string/include/string.h"

static int lr_move(root_t *root, minos_t *minos, uint8_t action)
{
    if (action == false)
        minos->pos.x -= (minos->pos.x > 2) ? 2 : 0;
    else
        minos->pos.x += (minos->pos.x + (minos->height * 2)
            < (ODIM.x * 2) - 2) ? 2 : 0;
    return (0);
}

static uint8_t which_action(root_t *root, int key)
{
    uint8_t action = 6;

    for (int i = 5; i + 1; --i)
        if (key == R_BINDS[i]) {
            action = i;
            break;
        }
    return (action);
}

static int process_actions(root_t *root, int key)
{
    uint8_t action = which_action(root, key);

    switch (action) {
    case 0 ... 1:
        lr_move(root, GAME_CURRENT, action);
        break;
    case 2:
        rotate_minos(GAME_CURRENT);
        break;
    case 3:
        CLOCK.ellapsed = CLOCK.level_time_descent + 1;
        break;
    case 4:
        while (getch() == ERR)
            mvprintw(0, 0, "pause !");
        break;
    case 5:
        return (1);
    }
    return (0);
}

int get_inputs(root_t *root)
{
    int key;

    if (!root)
        return (1);
    key = getch();
    if (key == ERR)
        return (0);
    if (key == 4) return (1);
    if (process_actions(root, key))
        return (1);
    return (0);
}