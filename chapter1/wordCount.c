#include <stdio.h>

#define YES 1
#define NO 0
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

int main(void) {
  int c, wc, lc, cc;
  int inword = NO;
  wc = lc = cc = 0;
  while((c = getchar()) != EOF) {
    cc++;
    if (c == NEWLINE)
      lc++;
    if (c == TAB || c == SPACE || c == NEWLINE)
      inword = NO;
    else if (!inword) {
      wc++;
      inword = YES;
    }
  }
  printf("%d %d %d \n", lc, wc, cc);
  return 0;
}