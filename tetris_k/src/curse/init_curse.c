/*
** EPITECH PROJECT, 2020
** init_curse
** File description:
** inits and close curse window
*/

#include "../../include/define.h"
#include "../../include/my.h"
#include "../../include/tetris.h"
#include "../../include/library/_string/include/string.h"

/* static
void middle(options_t *option, char **tab, char *texture)
{
    char height = ODIM.y;
    char width = ODIM.x * 2;

    tab[(int)height] = NULL;
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j)
            tab[i][j] = texture[1];
        tab[i][0] = texture[0];
        tab[i][(int)width - 1] = texture[2];
        tab[i][(int)width] = '\0';
    }
}

static
void top_bottom(options_t *option, char **tab, char *texture)
{
    char height = ODIM.Y;
    char width = ODIM.x * 2;

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
    char **map = malloc(sizeof(char *) * ODIM.y + 1);

    if (!map)
        return (NULL);
    for (int i = 0; i < ODIM.y; ++i) {
        if (!(map[i] = malloc((ODIM.x * 2) + 1)))
            free_done((void **)map, i);
    }
    top_bottom(option, map, "+-++-+");
    middle(options, map, "| |");
    return (map);
}
 */
static void
init_curse_struct(game_t *game, options_t *option)
{
    int i = 0;

    game->in_game = true;
    game->catch = '\0';
    ELEMENT.filepath = malloc(sizeof(char *) * 3);
    ELEMENT.filepath[0] = "data/title_game.txt";
    ELEMENT.filepath[1] = "data/score.txt";
    ELEMENT.filepath[2] = "data/game.txt";
    ELEMENT.position = (vector2_t []){{1, 0}, {1, 7}, {31, 0}};
    MAP = create_map(option);
}

void init_curse(game_t *game, options_t *option)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    echo();
    init_curse_struct(game, option);
}

void close_curse(void)
{
    endwin();
}