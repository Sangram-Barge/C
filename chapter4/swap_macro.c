#include <stdio.h>
#define SWAP(A, B) \
  int temp = A;    \
  A = B;           \
  B = temp;
int main(void)
{
  int a = 10, b = 45;
  printf("a : %d, b %d\n", a, b);
  SWAP(a, b);
  printf("a : %d, b %d\n", a, b);
}
