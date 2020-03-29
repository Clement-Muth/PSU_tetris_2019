/*
** EPITECH PROJECT, 2020
** destroy_minos
** File description:
** frees a piece
*/

#include "my.h"
#include "minos.h"

void
destroy_minos(minos_t *minos)
{
    if (!minos)
        return;
    multi_free("21", minos->minos, minos->name);
    free(minos);
}