#include <stdio.h>
int getbits(unsigned x, unsigned p, unsigned n);
int main(void) {
  int a = 0xD1; 
  printf("%d -> %d \n", a, getbits(a, 4, 3));
  return 0;
}

int getbits(unsigned x, unsigned p, unsigned n) {
  return ( x >> (p+1-n) & ~(~0 << n));
}