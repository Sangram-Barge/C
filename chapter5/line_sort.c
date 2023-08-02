#include <stdio.h>
#include <string.h>
#include "alloc_free.c"

#define MAXLEN 100
#define LINE 100

int get_line(char line[], int maxlen);
int readlines(char *lineptr[], int maxlines);
// void writelines(char *lineptr[], int maxlines);

int main(void) {
  char *lineptr[LINE];
  printf("%d \n", readlines(lineptr, LINE));
}

int readlines(char *lineptr[], int maxlines) {
  int count = 0, len;
  char line[MAXLEN], *p;
  while ((len = get_line(line, MAXLEN)) > 0)
      if (count > maxlines) return -1;
      else if ((p = alloc(len)) == 0) return -1;
      else {
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[count++] = p;
      }
  return count;
}

int get_line(char line[], int maxlen) {
  int c, len = 0;
  while ((c = getchar()) != '\n' && len < maxlen) line[len++] = c;
  return len;
}
