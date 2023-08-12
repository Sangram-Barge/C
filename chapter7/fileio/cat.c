#include <stdio.h>

void file_copy(FILE *fp);

int main(int argc, char *argv[]) {
  FILE *fp;
  if (argc == 1) file_copy(stdin);
  else {
    while (--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("cant open file %s\n", *argv);
        break;
      } else {
        file_copy(fp);
        fclose(fp);
      }
    }
  }
}

void file_copy(FILE *fp) {
  int c;
  while((c = getc(fp)) != EOF) putc(c, stdout);
}
