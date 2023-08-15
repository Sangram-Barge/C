#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512
#define PMODE 0644

void error(char *e, char *s);

int main(int argc, char *argv[]) {
  int f1, f2, n;
  char buff[BUFSIZE];
  if (argc != 3) error("usage cp : from -> to", NULL);
  if ((f1 = open(argv[1], 0)) == -1) error("cannot open file %s", argv[1]);
  if ((f2 = creat(argv[2], PMODE)) == -1) error("cannot create file %s", argv[2]);
  while ((n = read(f1, buff, BUFSIZE)) != 0) 
    if (write(f2, buff, n) != n) error("write error", NULL);
  exit(1);
}

void error(char *e, char *s) {
  printf(e, s);
  printf("\n");
  exit(1);
}
