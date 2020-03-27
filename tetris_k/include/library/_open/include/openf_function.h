/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** openf_function
*/

#ifndef OPENF_FUNCTION_H_
#define OPENF_FUNCTION_H_

openf_t *
openf_init(const char *restrict filepath, size_t nread);

bool
openf_readf(const char *__restrict__ filepath);

size_t
nb_linef(FILE *fd);

#endif /* !OPENF_FUNCTION_H_ */