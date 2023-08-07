#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/get_line.c"
#include "../lib/alloc_free.c"

#define MAXLINES 1000
#define MAXLEN 1000
#define FLAG '-'
int get_lines(char *lines[]);
void writelines(char *lines[], int startat, int endat);

int main(int argc, char *argv[]) {
  int nflag = 0, n;
  if (argc == 3)
    while (--argc)
      if (*(argv[1]) == FLAG) nflag = 1;
  n = nflag ? atoi(argv[2]) : 10;

  static char *lines[MAXLINES];
  int nlines = get_lines(lines);
  if (nlines < n) writelines(lines, 0, nlines);
  else writelines(lines, nlines - n, nlines);
  return 0;
}

void writelines(char *lines[], int startat, int endat) {
  while(startat++  < endat) printf("%s\n",lines[startat-1]);
}

int get_lines(char *lines[]) {
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
