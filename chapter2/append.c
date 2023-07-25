#include <stdio.h>
#define EOL '\0'
#define SPACE ' '
void append(char[], char[]);
int main(void) {
  char s[20] = "hello", t[20] = "there";
  printf("before %s \n", s);
  append(s, t);
  printf("after %s \n", s);
  return 0;
}

void append(char s[], char t[]) {
  int i = 0, j = 0;
  while( s[i] != EOL ) i++;
  s[i++] = SPACE;
  while((s[i++] = t[j++]) != EOL);
  s[i] = EOL;
}
