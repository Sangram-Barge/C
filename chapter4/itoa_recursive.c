#include <stdio.h>

void itoa(int num);
char numstr[100];  
int main(void) {
  int a = 127640;
  itoa(a);
  printf("%s: %d\n", numstr, a);
}

void itoa(int num) {
  static int i = 0;
  if (num <= 0) return;
  itoa(num/10);
  numstr[i++] = num % 10 + '0';
}
