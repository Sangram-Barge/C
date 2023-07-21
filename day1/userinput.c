#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, c;
  printf("enter a number : ");
  scanf("%d", &a);
  printf("enter another number : ");
  scanf("%d", &b);
  printf("sum is : %d \n", a + b);
  char name[20];
  char surname[30];
  printf("enter your name : ");
  scanf("%s", name);
  printf("your name is %s \n", name);
  printf("enter your surname : ");
  fgets(surname, 30, stdin);
  printf("your surname is : %s", surname);
  return 0;
}