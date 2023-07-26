#include <stdio.h>
int invert(unsigned x, unsigned p, unsigned n);
int main(void) {
  printf("%d masked to %d \n", 42, invert(42, 4, 3));
}

int invert(unsigned x, unsigned p, unsigned n) {
  int mask = 0;
  return (~(~mask << n) << (p+1-n)) ^ x;
}