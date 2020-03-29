/*
** EPITECH PROJECT, 2020
** timer
** File description:
** prints a timer
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

static int ellapsed_second(clock_t *myclock)
{
    static clock_t ellapsed = 0;

    ellapsed = clock() - (*myclock);
    if (ellapsed > 1000000) {
        *myclock = clock();
        return (1);
    }
    return (0);
}

static void format_time(char time[5], int min, int sec)
{
    time[0] = ((int)(min / 10) % 10) + 48;
    time[1] = (min % 10) + 48;
    time[3] = ((int)(sec / 10) % 10) + 48;
    time[4] = (sec % 10) + 48;
}

void print_time(clock_t *myclock, vector2_t pos)
{
    static char time[5] = "00:00";
    static int min = 0;
    static int sec = 0;

    if (ellapsed_second(myclock)) {
        ++sec;
        if (sec == 60) {
            ++min;
            sec = 0;
        }
        if (min == 60)
            min = 0;
        format_time(time, min, sec);
    }
    mvprintw(pos.y, pos.x, "%s", time);
}
