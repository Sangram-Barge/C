#include <stdio.h>
void printd(int n);
int main(void) {
  printd(12345678);
}

void printd(int n) {
  int i;
  if(n < 0) {
    putchar('-');
    n = -n;
  }
  if ((i = n/10) != 0)
    printd(i);
  putchar(n % 10 + '0');
}
