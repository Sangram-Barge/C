#include <stdio.h>
#define EOL '\n'
#define EOFF '\0'
int get_line(char line[], int maxlen) {
  int c, len = 0;
  while( len < maxlen - 1 && (c = getchar()) != EOF && c != '\n' ) line[len++] = c;
  if (c == '\n') line[len++] = c;
  line[len] = '\0';
  return len;
}