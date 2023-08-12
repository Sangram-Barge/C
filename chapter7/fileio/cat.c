#include <stdio.h>
#include <stdlib.h>

void f_copy(FILE *fps, FILE *fpd);

int main(int argc, char *argv[]) {
  FILE *fp;
  if (argc == 1) f_copy(stdin, stdout);
  else 
    while (--argc > 0 ) 
    if ((fp = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "cat: cant open file %s\n", *argv);
      exit(1);
    } else {
      f_copy(fp, stdout);
      fclose(fp);
    }
  exit(0);
}

void f_copy(FILE *fps, FILE *fpd) {
  int c;
  while ((c = getc(fps)) != EOF) putc(c, fpd);
}
