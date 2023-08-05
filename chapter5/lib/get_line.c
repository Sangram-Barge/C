#include <stdio.h>
#define EOL '\n'
#define EOFF '\0'
int get_line(char line[], int maxlen) {
  int len = 0, c;
  while (len < maxlen && (c = getchar()) != EOF && c != EOL) line[len++] = c;
  if (c == EOL) line[len++] = c;
  line[len] = EOFF;
  return len;
}