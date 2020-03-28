/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** openf_struct
*/

#ifndef OPENF_STRUCT_H_
#define OPENF_STRUCT_H_

typedef struct openf_s
{
    char *lineptr;
    size_t nline;
    size_t nread;
    FILE *stream;
} openf_t;

#endif /* !OPENF_STRUCT_H_ */