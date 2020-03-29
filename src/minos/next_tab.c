/*
** EPITECH PROJECT, 2020
** next_tab
** File description:
** next_tab
*/

#include "my.h"
#include "minos.h"

static void fill_middle(char **tab, char width, char height)
{
    char texture[3] = "| |";

    tab[(int)height] = NULL;
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j)
            tab[i][j] = texture[1];
        tab[i][0] = texture[0];
        tab[i][(int)width - 1] = texture[2];
        tab[i][(int)width] = '\0';
    }
}

static void fill_top_bottom(char **tab, char width, char height)
{
    char texture[6] = "/-\\\\-/";

    tab[0][0] = texture[0];
    tab[0][width - 1] = texture[2];
    tab[height - 1][0] = texture[3];
    tab[height - 1][width - 1] = texture[5];
    for (int i = 1; i < width - 1; ++i) {
        tab[0][i] = texture[1];
        tab[height - 1][i] = texture[4];
    }
    tab[0][(int)width] = '\0';
    tab[(int)height - 1][(int)width] = '\0';
}

static char **first_layer(char width, char height)
{
    char **ret = malloc(sizeof(char *) * (height + 1));

    if (!ret)
        return (ret);
    for (int i = 0; i < height; ++i) {
        if ((ret[i] = malloc(width + 1)) == NULL) {
            free_done((void **)ret, i);
            return (NULL);
        }
    }
    fill_top_bottom(ret, width, height);
    fill_middle(ret, width, height);
    return (ret);
}

static void second_layer(char **tab, minos_t *minos)
{
    for (int i = 0; minos->minos[i]; ++i) {
        for (int j = 0; minos->minos[i][j]; ++j) {
            tab[i + 1][j + 2] = minos->minos[i][j];
        }
    }
}

char **create_next_tab(minos_t *minos)
{
    char **ret = first_layer(minos->width * 2 + 3, minos->height + 2);

    if (ret) {
        second_layer(ret, minos);
    }
    return (ret);
}
