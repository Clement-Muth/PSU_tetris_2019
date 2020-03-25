/*
** EPITECH PROJECT, 2020
** get_file
** File description:
** get_file
*/

#include "../../include/my.h"


char **get_file(char *filename)
{
    struct stat st;
    int fd = open(filename, O_RDONLY);
    char *file;
    char **ret;

    if (fd == -1) {
        free(filename);
        return (NULL);
    }
    stat(filename, &st);
    free(filename);
    if (!(file = malloc(st.st_size + 1)))
        return (NULL);
    read(fd, file, st.st_size);
    file[st.st_size] = '\0';
    ret = parse(file, '\n');
    free(file);
    return (ret);
}
