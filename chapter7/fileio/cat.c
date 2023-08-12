#include <stdio.h>

void f_copy(FILE *fps, FILE *fpd);

int main(int argc, char *argv[]) {
  FILE *fp;
  if (argc == 1) f_copy(stdin, stdout);
  else 
    while (--argc > 0 ) 
    if ((fp = fopen(*++argv, "r")) == NULL) {
      printf("cat: cant open file %s\n", *argv);
      break;
    } else {
      f_copy(fp, stdout);
      fclose(fp);
    }
}

void f_copy(FILE *fps, FILE *fpd) {
  int c;
  while ((c = getc(fps)) != EOF) putc(c, fpd);
}
