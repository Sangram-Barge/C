#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/get_line.c"

#define MAXLEN 100
#define MAXLINES 100
#define MAXWORDS MAXLEN * MAXLINES
struct words {
  char *word;
  int count;
};

int read_lines(char *lines[]);

int main() {
  char *lines[MAXLINES], *words[MAXWORDS];
  int nlines, nwords;
  nlines = read_lines(lines);
  nwords = wordarray(lines, words, nlines);
  return 0;
}
