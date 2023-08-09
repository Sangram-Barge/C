#include <stdio.h>
#include <string.h>
#include "../lib/alloc_free.c"

#define MAXLEN 100
#define LINE 100

int get_line(char line[], int maxlen);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void shell_sort(char *lineptr[], int nlines);
int readlinesinplace(char *lineptr[], int maxlines);

int main(void) {
  int nlines;
  char *lineptr[LINE];
  if((nlines = readlinesinplace(lineptr, LINE)) >= 0){
    shell_sort(lineptr, nlines);
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

int readlinesinplace(char *lineptr[], int maxlines) {
  int count = 0, len = 0;
  char *p, line[MAXLEN];
  while ((len = get_line(lineptr[count], MAXLEN)) != 0)
    if (count >= LINE) return -1;
    else {
      printf("%s", lineptr[count]);
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

void shell_sort(char *lineptr[], int nlines){
  char *temp;
  int gap, i, j;
  for(gap = nlines/2; gap > 0; gap /= 2)
    for(i = gap; i < nlines; i++)
      for(j = i - gap; j >=0; j-=gap) {
        if (strcmp(lineptr[j], lineptr[j+gap]) <= 0) break;
        temp = lineptr[j];
        lineptr[j] = lineptr[j + gap];
        lineptr[j + gap] = temp;
      }
}
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
