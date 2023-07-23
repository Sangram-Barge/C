#include <stdio.h>

#define BLANK = ' '
#define TAB = '\t'
#define NEWL = '\n'


int main() {
  int cb = 0, ct = 0, cnl = 0;
  int c;
  while((c = getchar()) != EOF)
    if(c == ' ') cb++;
    else if(c == '\t') ct++;
    else if(c == '\n') cnl++;
    else continue;
  printf("blanks %d, tabs %d, newlines %d \n", cb, ct, cnl);
}