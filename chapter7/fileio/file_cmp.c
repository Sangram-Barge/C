#include <stdio.h>
#include <stdlib.h>
#include "../../lib/get_line.c"

void open_files(char *fname[], FILE **fp1, FILE **fp2);
void file_cmp(FILE **fp1,FILE **fp2);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "two input files required");
  }
  FILE *fp1, *fp2;
  open_files(argv, &fp1, &fp2);
  file_cmp(&fp1, &fp2);
}

void open_files(char *fnames[], FILE **fp1, FILE **fp2) {
  if ((*fp1 = fopen(fnames[1], "r")) == NULL) { 
    fprintf(stderr, "error opening file %s\n", fnames[1]);
    exit(1);
  }
  if ((*fp2 = fopen(fnames[2], "r")) == NULL){
    fprintf(stderr, "error opening file %s\n", fnames[1]);
    exit(1);
  }
}

void file_cmp(FILE **fp1, FILE **fp2) {
  int f1c, f2c, count = 0;
  while ((f1c = getc(*fp1)) == (f2c = getc(*fp2)) && f1c != EOF && f2c != EOF) count++;
  if (f1c == EOF && f2c == EOF) printf("files are identical \n");
  else printf("files differ at %d\n", count);
}
