/*
** EPITECH PROJECT, 2020
** tetris_k [WSL: Debian]
** File description:
** create_map
*/

#include "../../include/my.h"
#include "../../include/define.h"
#include "../../include/minos.h"

static void
middle(options_t *option, char **tab, char *texture)
{
    int height = ODIM.y + 2;
    int width = ODIM.x * 2 + 2;

    tab[(int)height] = NULL;
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j)
            tab[i][j] = texture[1];
        tab[i][0] = texture[0];
        tab[i][(int)width - 1] = texture[2];
        tab[i][(int)width] = '\0';
    }
}

static void
top_bottom(options_t *option, char **tab, char *texture)
{
    int height = ODIM.y + 2;
    int width = ODIM.x * 2 + 2;

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

char **
create_map(options_t *option)
{
    char **map = malloc(sizeof(char *) * (ODIM.y + 3));

    if (!map)
        return (NULL);
    for (int i = 0; i < ODIM.y + 2; ++i) {
        if ((map[i] = malloc((ODIM.x * 2) + 3)) == NULL)
            free_done((void **)map, i);
    }
    top_bottom(option, map, "+-++-+");
    middle(option, map, "| |");
    return (map);
}
