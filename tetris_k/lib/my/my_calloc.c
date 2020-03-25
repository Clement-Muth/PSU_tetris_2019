/*
** EPITECH PROJECT, 2019
** my_calloc
** File description:
** my_calloc
*/

#include <stdlib.h>

char *my_calloc(int type, int len)
{
    char *res = malloc(len);

    if (res == NULL)
        return (NULL);
    for (int i = len; i; --i)
        res[i - 1] = '\0';
    return (res);
}
