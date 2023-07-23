#include <stdio.h>

int lower(int c);

int main(void) {
  printf("%c \n", lower('+'));
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z') return c + 'a' - 'A';
  else return c;
}