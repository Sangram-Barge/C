#include <stdio.h>
#include "lib/get_line.c"
#include "lib/pattern.c"

#define MAXLINE 1000

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  if (argc != 2) printf("usage: find pattern\n");
  else
    while (get_line(line, MAXLINE) > 0)
      if (idx(line, argv[1]) >= 0)
        printf("%s", line);
}