/*
** EPITECH PROJECT, 2020
** read_minos
** File description:
** read tetriminos
*/

#include "../../include/my.h"
#include "../../include/minos.h"
#include <dirent.h>

/* char **get_file(char *filename) */
/* { */
/*     struct stat st; */
/*     int fd = open(filename, O_RDONLY); */
/*     char *file; */
/*     char **ret; */

/*     if (fd == -1) { */
/*         free(filename); */
/*         return (NULL); */
/*     } */
/*     stat(filename, &st); */
/*     free(filename); */
/*     if (!(file = malloc(st.st_size + 1))) */
/*         return (NULL); */
/*     read(fd, file, st.st_size); */
/*     file[st.st_size] = '\0'; */
/*     ret = parse(file, '\n'); */
/*     free(file); */
/*     return (ret); */
/* } */

/* int get_number(char **fline, char *_int) */
/* { */
/*     *_int = (char)my_atoie(*fline); */
/*     if (_int == 0) */
/*         return (1); */
/*     while (**fline && ISNUM(**fline)) */
/*         ++*fline; */
/*     ++*fline; */
/*     return (0); */
/* } */

/* int get_numbers(char *fline, minos_t *minos) */
/* { */
/*     if (get_number(&fline, &minos->width) || */
/*         get_number(&fline, &minos->height)) */
/*         return (1); */
/*     minos->color = (char)my_atoie(fline); */
/*     if (minos->color == 0) */
/*         return (1); */
/*     while (ISNUM(*fline)) */
/*         ++fline; */
/*     if (*fline) */
/*         return (1); */
/*     return (0); */
/* } */

/* int is_correct(char *line) */
/* { */
/*     while (*line) { */
/*         if (*line != '*' && *line != ' ') */
/*             return (1); */
/*         ++line; */
/*     } */
/*     return (0); */
/* } */

/* int count_asterisk(char *line) */
/* { */
/*     int ret = 0; */

/*     while (*line) { */
/*         ret += (*line == '*'); */
/*         ++line; */
/*     } */
/*     return (ret); */
/* } */

/* int check_minos(char **minos, char width) */
/* { */
/*     int asterisks = 0; */

/*     while (*minos) { */
/*         asterisks = count_asterisk(*minos); */
/*         if (asterisks > width || */
/*             asterisks <= 0 || */
/*             is_correct(*minos)) */
/*             return (1); */
/*         ++minos; */
/*     } */
/*     return (0); */
/* } */

/* int check_file(char **file, minos_t *minos) */
/* { */
/*     if (get_numbers(*file, minos) || */
/*         my_char2len(file + 1) != minos->height || */
/*         check_minos(file + 1, minos->width)) */
/*         return (1); */
/*     return  (0); */
/* } */

/* char *format_line(char asterisks) */
/* { */
/*     int i = 0; */
/*     char *new_line = malloc(asterisks * 2); */

/*     if (new_line == NULL) */
/*         return (NULL); */
/*     while (asterisks) { */
/*         new_line[i++] = '*'; */
/*         if (--asterisks) */
/*             new_line[i++] = ' '; */
/*     } */
/*     new_line[i] = '\0'; */
/*     return (new_line); */
/* } */

/* void free_done(char **to_free, int done) */
/* { */
/*     --done; */
/*     while (done != -1) { */
/*         free(to_free[done--]); */
/*     } */
/* } */

/* int format_piece(minos_t *new, char **piece) */
/* { */
/*     if (!(new->minos = malloc(sizeof(char *) * (new->height + 1)))) */
/*         return (1); */
/*     for (int i = 0; i < new->height; ++i) { */
/*         if (!(new->minos[i] = format_line((char)count_asterisk(piece[i])))) { */
/*             free_done(new->minos, i); */
/*             return (1); */
/*         } */
/*     } */
/*     new->minos[(int)new->height] = NULL; */
/*     return (0); */
/* } */

/* int add_minos(minos_t **minos, char *filename) */
/* { */
/*     char **file = get_file(my_glue_sep("tetriminos", filename ,'/')); */
/*     minos_t *new; */

/*     if (!file || (!(new = malloc(sizeof(minos_t))))) { */
/*         multi_free("2", file); */
/*         return (1); */
/*     } */
/*     if (check_file(file, new) || */
/*         format_piece(new, file + 1)) { */
/*         free(new); */
/*         multi_free("2", file); */
/*         return (1); */
/*     } */
/*     new->name = my_strdup(filename); */
/*     new->next = *minos; */
/*     *minos = new; */
/*     multi_free("2", file); */
/*     return (0); */
/* } */

/* int is_ext(char *str, char *ext) */
/* { */
/*     while (*str != '.') { */
/*         if (*str == '\0') */
/*             return (0); */
/*         ++str; */
/*     } */
/*     while (*str) { */
/*         if (*str != *ext++) */
/*             return (0); */
/*         ++str; */
/*     } */
/*     return (*str == '\0' && *ext == '\0'); */
/* } */

/* void free_minos(minos_t *minos) */
/* { */
/*     minos_t *tmp = minos; */

/*     while (minos) { */
/*         multi_free("21", minos->minos, minos->name); */
/*         tmp = minos->next; */
/*         free(minos); */
/*         minos = tmp; */
/*     } */
/* } */

/* int fill_minos(minos_t **minos, char *name) */
/* { */
/*     if (is_ext(name, ".tetriminos")) { */
/*         if (add_minos(minos, name)) { */
/*             my_printf(2, "Incorrect file: [%s]\n", name); */
/*             free_minos(*minos); */
/*             return (1); */
/*         } */
/*     } */
/*     return (0); */
/* } */

minos_t *read_minos(char *directory)
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
        if (fill_minos(&minos, dirent->d_name)) {
            closedir(dir);
            return (NULL);
        }
    }
    if (minos == NULL)
        my_putstr(2, "No file found\n");
    closedir(dir);
    return (minos);
}
