#include <stdio.h>
#include <stdlib.h>

void open_files(char *fname[], FILE **fp1, FILE **fp2);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "two input files required");
  }
  FILE *fp1, *fp2;
  open_files(argv, &fp1, &fp2);
  int c;
  while((c = getc(fp1)) != EOF) putc(c, stdout);
  while((c = getc(fp2)) != EOF) putc(c, stdout);
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
  printf("%s %s \n", fnames[1], fnames[2]);
}
