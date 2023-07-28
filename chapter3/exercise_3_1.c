#include <stdio.h>
#define NEWLINE '\n'
#define TAB '\t'
#define SLASH '\\'

void expand(char line[], char copy[]);
int main(void) {
  char line[] = "hello\nThis is \t sangram barge";
  char copy[] = "                                   ";
  expand(line, copy);
  printf("first line: %s \nsecond line: %s\n", line, copy);
}

void expand(char line[], char copy[]) {
  int i = 0, j = 0, c;
  while((c = line[i++]) != '\0') {
    switch(c) {
      case NEWLINE:{
        copy[j++] = SLASH;
        copy[j++] = 'n';
        break;
      }
      case TAB:{
        copy[j++] = SLASH;
        copy[j++] = 't';
        break;
      }  
      default: {
        copy[j++] = c;
        break;
      }
    }
  }
  copy[j] = '\0';
}