#include <stdio.h>
static int non_leap_year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap_year[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int (*daytab)[13] = (int[][13]){
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void day_of_month(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main(void) {
  int doy = day_of_year(2023, 8, 1);
  printf("%d \n", doy);
  int year = 2023, month, day;
  day_of_month(year, doy, &month, &day);
  printf("for day %d of year %d -> month is %d and day is %d \n", doy, year, month, day);
}

int day_of_year(int year, int month, int day) {
  int leap, i;
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (i = 1; i < month; i++) 
    day += *(*(daytab+leap)+i);
  return day;
}

void day_of_month(int year, int yearday, int *pmonth, int *pday) {
  int leap, i;
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= *(*(daytab+leap)+i);
  *pmonth = i;
  *pday = yearday;
}
