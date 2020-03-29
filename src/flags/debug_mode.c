/*
** EPITECH PROJECT, 2020
** debug_mode
** File description:
** debug mode for tetris
*/

#include "my.h"
#include "minos.h"
static char *stringize(int c)
{
    char *ret = malloc(2);

    ret[0] = (char)c;
    ret[1] = '\0';
    return (ret);
}

static char *my_translate(int c, int *good)
{
    int trans_i[5] = {32, 258, 259, 260, 261};
    char *trans_a[5] = {"(space)", "^EOB", "^EOA", "^EOD", "^EOC"};

    for (int i = 0; i < 5; ++i)
        if (c == trans_i[i]) return (trans_a[i]);
    *good = 1;
    return (stringize(c));
}

static void special_print(options_t *options, char *text, int index)
{
    int good = 0;
    char *str = TRBINDS(index);

    my_printf(1, text, str);
    if (good)
        free(str);
}

int debug_mode(options_t *options)
{
    char *input = NULL;

    my_putstr (1, "*** DEBUG MODE ***\n");
    special_print(options, "Key Left :    %s\n", 0);
    special_print(options, "Key Right :    %s\n", 1);
    special_print(options, "Key Turn :    %s\n", 2);
    special_print(options, "Key Drop :    %s\n", 3);
    special_print(options, "Key Quit :    %s\n", 4);
    special_print(options, "Key Pause :    %s\n", 5);
    my_printf (1, "Next :    %s\n", (options->no_next ? "No": "Yes"));
    my_printf(1, "Level :    %d\n", options->level);
    my_printf (1, "dim :    %d*%d\n", options->dim.y, options->dim.x);
    print_minos(options->minos);
    my_putstr(1, "Press any key\n");
    read(0, &input, 1);
    return (0);
}
