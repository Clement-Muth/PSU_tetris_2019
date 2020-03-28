/*
** EPITECH PROJECT, 2020
** read_minos
** File description:
** read tetriminos
*/

#include "../../include/my.h"
#include "../../include/minos.h"
#include <dirent.h>

minos_t *read_minos(char *directory, vector2_t dim)
{
    DIR *dir;
    struct dirent *dirent;
    minos_t *minos = NULL;

    dir = opendir(directory);
    if (dir == NULL) {
        my_putstr(2, "No \"tetriminos\" directory found");
        return (NULL);
    }
    while ((dirent = readdir(dir))) {
        if (fill_minos(&minos, dirent->d_name, dim)) {
            closedir(dir);
            return (NULL);
        }
    }
    if (minos == NULL)
        my_putstr(2, "No file found\n");
    closedir(dir);
    return (minos);
}
