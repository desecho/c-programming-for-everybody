#include <stdio.h>
#include <stdlib.h>

struct simpledate {
    int day;
    int month;
    int year;
};

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(pd) /* set day of year from month, day */
struct simpledate *pd;
{
    int i;
    int y;
    int days = pd->day;

    if (pd->year == 2023) {
        y = 0;
    } else if (pd->year == 2024) {
        y = 1;
    }
    for (i = 1; i < pd->month; i++) {
        days += day_tab[y][i];
    }

    return days;
}

void dump_date(pd) /* print date from year, month, day */
struct simpledate *pd;
{
    printf("%d/%02d/%2d\n", pd->year, pd->month, pd->day);
}

int main() {
    void dump_date();
    printf("Playing with structures\n");
    struct simpledate sd;

    sd.year = 2023;
    sd.month = 2;
    sd.day = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2023;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2024;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
}
