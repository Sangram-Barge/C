#include <stdio.h>
#define NEWLINE '\n'
#define TAB '\t'
#define SLASH '\\'

void expand(char s[], char t[]);
int main(void) {
  char s[] = "hello\nThis is \t sangram barge";
  char t[] = "                                   ";
  expand(s, t);
  printf("first line: %s \nsecond line: %s\n", s, t);
}

void expand(char s[], char t[]) {
  int i = 0, j = 0, c;
  while((c = s[i++]) != '\0') {
    switch(c) {
      case NEWLINE:{
        t[j++] = SLASH;
        t[j++] = 'n';
        break;
      }
      case TAB:{
        t[j++] = SLASH;
        t[j++] = 't';
        break;
      }  
      default: {
        t[j++] = c;
        break;
      }
    }
  }
  t[j] = '\0';
}