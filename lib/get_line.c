#include <stdio.h>
#include <string.h>
#include "alloc_free.c"

#define EOL '\n'
#define EOFF '\0'
#define MAXLEN 100
#define NULLL 0
#define SPACE ' '

int get_line(char line[], int maxlen) {
  int c, len = 0;
  while( len < maxlen - 1 && (c = getchar()) != EOF && c != '\n' ) line[len++] = c;
  if (c == '\n') line[len++] = c;
  line[len] = '\0';
  return len;
}

int read_lines(char *lines[]) {
  char l[MAXLEN], *p;
  int line_count = 0, line_len;
  while ((line_len = get_line(l, MAXLEN)) != 0){
    if (line_count >= MAXLEN || (p = alloc(line_len)) == NULLL) return -1;
    else {
      l[line_len - 1] = '\0';
      strcpy(p, l);
      lines[line_count++] = p;
    }
  }
  return line_count;
}

int wordarray(char *lines[], char *words[], int nlines) {
  int count, swp = 0, ewp = 0, wr = 0;
  char *w, c;
  while (nlines--) {

  }
  return count;
}
