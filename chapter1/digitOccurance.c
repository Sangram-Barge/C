#include <stdio.h>

#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

int main(void) {
  int otherc, blankc, c;
  int digitocc[10];
  otherc = blankc = 0;
  for(int i = 0; i < 10; i++) 
    digitocc[i] = 0;
  while ((c = getchar()) != EOF) {
    if (c == TAB || c == SPACE || c == NEWLINE) blankc++;
    else if (c >= '0' && c <= '9') digitocc[c - '0']++;
    else otherc++;
  }
  for (int i = 0; i < 10; i++) 
    printf("%d occured %d times\n", i, digitocc[i]);
  printf("blanks : %d, other %d\n", blankc, otherc);
}