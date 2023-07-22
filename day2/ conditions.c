#include <stdio.h>
#include <stdlib.h>

void max(int a, int b) {
  if (a > b) 
    printf("%d is greater than %d", a, b);
  else
    printf("%d is greater than %d", b, a);
  return;
}

int main() {
  int a, b;
  printf("enter a number : ");
  scanf("%d", &a);
  printf("enter another number : ");
  scanf("%d", &b);
  max(a, b);
}