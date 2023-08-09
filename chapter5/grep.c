#include <stdio.h>
#include "../lib/get_line.c"
#include "../lib/pattern.c"

#define MAXLINE 1000
#define OPTFLAG '-'
#define EFLAG 'x'
#define NFLAG 'n'

int main(int argc, char *argv[]) {
  char line[MAXLINE], *s;
  int lineflag = 0, exceptflag = 0, linecount = 0;

  while(--argc > 0 && (*++argv)[0] == OPTFLAG)
    for (s = argv[0] + 1; *s != EOFF; s++)
      switch(*s) {
        case EFLAG:
          exceptflag = 1;
          break;
        case NFLAG:
          lineflag = 1;
          break;
        default:
          printf("invalid input\n");
          argc = 0;
          break;
      }
  printf("test flags except flag %d number flag %d\n", exceptflag, lineflag);
  if(argc != 1) printf("Usage: find -x -n patter \n");
  else
    while (get_line(line, MAXLINE) > 0){
      linecount++;
      if ((idx(line, *argv) >= 0) != exceptflag){
        if (linecount)
          printf("%d ",linecount);
        printf("%s", line);
      }
    }
}
