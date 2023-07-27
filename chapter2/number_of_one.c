#include <stdio.h>
int getones(unsigned a);
int main(void) {
  int a = -0xffff;
  printf("no of 1's in %d is %d \n", a, getones(a));
}

int getones(unsigned a) {
  int count = 0;
  for( count = 0; a != 0; a >>= 1)
    if( a & 01 )
      count++;
  return count;
}