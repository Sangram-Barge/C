#include <stdio.h>
void swap(int *a, int *b);
int main(void) {
  int a = 10, b = 45;
  printf("a: %d, b: %d\n", a, b);
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

