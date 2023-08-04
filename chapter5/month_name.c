#include<stdio.h>
char *month_name(int n);
int main(void) {
  int n = 13;
  printf("%d month is %s \n", n, month_name(n));
}

char *month_name(int n) {
  static char *month[] = {
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
  return (n > 0 && n < 13) ? month[n] : month[0];
}
