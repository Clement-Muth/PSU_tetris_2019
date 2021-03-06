/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** strcat
*/

#include "my.h"

static char *first_action(char *str1, char *str2)
{
    char *ret = malloc(my_strlen(str1) + my_strlen(str2) + 1);
    char *tmp = ret;

    if (ret == NULL) {
        free(ret);
        return (NULL);
    }
    while (str1 && *str1) {
        *tmp = *str1++;
        tmp++;
    }
    while (str2 && *str2) {
        *tmp = *str2++;
        tmp++;
    }
    *tmp = '\0';
    return (ret);
}

char *my_strcat(char *str1, char *str2)
{
    char *ret = first_action(str1, str2);

    freeif(str1);
    freeif(str2);
    return (ret);
}

static char *second_action(char *str1, char *cpy, int size)
{
    char *ret = malloc(my_strlen(str1) + size + 1);
    char *tmp = ret;

    if (ret == NULL) {
        free(ret);
        return (NULL);
    }
    while (str1 && *str1) {
        *tmp = *str1++;
        tmp++;
    }
    for (int i = 0; i < size; ++i) {
        *tmp = *cpy++;
        tmp++;
    }
    *tmp = '\0';
    return (ret);
}

char *my_strncat(char *str1, char *cpy, int size)
{
    char *ret = second_action(str1, cpy, size);

    freeif(str1);
    freeif(cpy);
    return (ret);
}
