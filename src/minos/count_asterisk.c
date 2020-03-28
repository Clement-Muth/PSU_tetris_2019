/*
** EPITECH PROJECT, 2020
** count_asterisk
** File description:
** counts asterisks
*/

int count_asterisk(char *line)
{
    int ret = 0;

    while (*line) {
        ret += (*line == '*');
        ++line;
    }
    return (ret);
}
