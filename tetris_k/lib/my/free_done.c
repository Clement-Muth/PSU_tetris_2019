/*
** EPITECH PROJECT, 2020
** free_done
** File description:
** free whats done
*/

#include "../../include/my.h"

void free_done(void **thing, int done)
{
    if (--done < 0)
        return;
    for (int i = 0; i < done; ++i) {
        freeif(thing[done]);
    }
}
