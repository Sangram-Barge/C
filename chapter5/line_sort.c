#include <stdio.h>
#include <string.h>
#include "alloc_free.c"

#define MAXLEN 100
#define LINE 100

int get_line(char line[], int maxlen);
int readlines(char *lineptr[], int maxlines);
// void writelines(char *lineptr[], int maxlines);

int main(void) {
  char *lineptr[LINE];
  printf("%d \n", readlines(lineptr, LINE));
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
  while ((c = getchar()) != '\n' && len < maxlen) line[len++] = c;
  return len;
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
 */
