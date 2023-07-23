#include <stdio.h>

int main() {
  int c;
  while((c = getchar()) != EOF) {
    if (c == '\t'){ 
      putchar('>');
      putchar('-');
    }
    else if (c == '\b') {
      putchar('<');
      putchar('-');
    }
    else putchar(c);
  }
}