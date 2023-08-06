#include <stdio.h>
#include <string.h>

struct date {
  int day;
  int month;
  int year;
  int yearday;
  char month_name[10];
};

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char *month_name[] = {
  "invalid month",
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

void day_of_month(struct date *dp);
void day_of_year(struct date *dp);

int main(void) {
  struct date hiredate1;
  struct date hiredate2;
  hiredate1.yearday = 218;
  hiredate1.year = 2023;
  day_of_month(&hiredate1);
  printf("hdate1 day : %d, month : %d, year : %d, yday : %d, month %s\n", hiredate1.day, hiredate1.month, hiredate1.year, hiredate1.yearday, hiredate2.month_name);

  hiredate2.year = 2023;
  hiredate2.day = 6;
  hiredate2.month = 8;
  day_of_year(&hiredate2);
  printf("hdate2 day : %d, month : %d, year : %d, yday : %d, month %s\n", hiredate2.day, hiredate2.month, hiredate2.year, hiredate2.yearday, hiredate2.month_name);
  return 0;
}

void day_of_month(struct date *dp) {
  int leap = (dp->year % 4 == 0 && dp -> year % 100 != 0) || dp -> year % 400 == 0;
  dp -> day = dp -> yearday;
  for (dp -> month = 1; dp -> day >= day_tab[leap][dp -> month]; dp -> month++)
    dp -> day -= day_tab[leap][dp->month];
  strcpy(dp -> month_name, month_name[dp -> month]);
} 

void day_of_year(struct date *dp) {
  int leap = (dp->year % 4 == 0 && dp -> year % 100 != 0) || dp -> year % 400 == 0;
  int i;
  for (i = 1, dp -> yearday = dp -> day; i < (dp -> month); i++) 
     dp -> yearday += day_tab[leap][i];
  strcpy(dp -> month_name, month_name[dp -> month]);
}
