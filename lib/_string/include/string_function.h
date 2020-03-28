/*
** EPITECH PROJECT, 2020
** CPE_dante_2019 [WSL: Debian]
** File description:
** string_function
*/

#ifndef STRING_FUNCTION_H_
#define STRING_FUNCTION_H_

bool
_strcmp(const char *restrict comparing, const char *restrict compared);

int
_atoi(const char *string);

void
_putchar(const char character, const int fd);

void
_putstr(const char *restrict string, const int fd);

size_t
_strlen(char *restrict string);

char *
_memalloc(char *memptr, size_t memsize);

#endif /* !STRING_FUNCTION_H_ */