#include <stdio.h>
#include <string.h>
#include "alloc_free.c"

#define MAXLEN 100
#define LINE 100

int get_line(char line[], int maxlen);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void sort(char *lineptr[], int nlines);

int main(void) {
  int nlines;
  char *lineptr[LINE];
  if((nlines = readlines(lineptr, LINE)) >= 0){
    sort(lineptr, nlines);
    writelines(lineptr, nlines);
  } else printf("input too long or some error occured");
}

int readlines(char *lineptr[], int maxlines) {
  int count = 0, len = 0;
  char *p, line[MAXLEN];
  while ((len = get_line(line, MAXLEN)) != 0)
    if (count >= LINE || (p = alloc(len)) == 0) return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[count++] = p;
    }
    return count;
}

int get_line(char line[], int maxlen) {
  int c, len = 0;
  while( len < maxlen - 1 && (c = getchar()) != EOF && c != '\n' ) line[len++] = c;
  if (c == '\n') line[len++] = c;
  line[len] = '\0';
  return len;
}

void writelines(char *lineptr[], int nlines) {
  while(--nlines >= 0) 
    printf("%s \n", *lineptr++);
}

void sort(char *lineptr[], int nlines){}
/*
   read all the lines of input
    -> read the line
    -> make sure that we do not exceed number of lines
    -> make sure that line does not exceed length limit
    -> if all passes are correct, allocate space in memory
    -> ppoint to allocated memory in pointer array
    -> return -1 if error
   sort them
   print them in order
get_line(s, lim)
char s[];
int lim;
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}
 */