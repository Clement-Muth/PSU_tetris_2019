/*
** EPITECH PROJECT, 2020
** tetris_k [WSL: Debian]
** File description:
** create_map
*/

#include "my.h"
#include "define.h"
#include "minos.h"

static void middle(root_t *root, char **tab, char *texture)
{
    int height = ODIM.y + 2;
    int width = ODIM.x * 2 - 1;

    tab[height] = NULL;
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j)
            tab[i][j] = texture[1];
        tab[i][0] = texture[0];
        tab[i][width - 1] = texture[2];
        tab[i][width] = '\0';
    }
}

static void top_bottom(root_t *root, char **tab, char *texture)
{
    int height = ODIM.y + 2;
    int width = ODIM.x * 2 - 1;

    tab[0][0] = texture[0];
    tab[0][width - 1] = texture[2];
    tab[height - 1][0] = texture[3];
    tab[height - 1][width - 1] = texture[5];
    for (int i = 1; i < width - 1; ++i) {
        tab[0][i] = texture[1];
        tab[height - 1][i] = texture[4];
    }
    tab[0][width] = '\0';
    tab[height - 1][width] = '\0';
}

char **create_map(root_t *root)
{
    char **map = malloc(sizeof(char *) * (ODIM.y + 3));

    if (!map)
        return (NULL);
    for (int i = 0; i < ODIM.y + 2; ++i) {
        if ((map[i] = malloc((ODIM.x * 2))) == NULL)
            free_done((void **)map, i);
    }
    top_bottom(root, map, "+-++-+");
    middle(root, map, "| |");
    return (map);
}
