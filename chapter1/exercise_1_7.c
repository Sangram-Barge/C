#include <stdio.h>

int main() {
  int c, blancCount = 0;
  while((c = getchar()) != EOF) {
    blancCount = (c == ' ') ? blancCount+1 : 0;
    if(blancCount <= 1) putchar(c);
  }
}