#include <stdio.h>
#define EOL '\0'
#define SPACE ' '

void delete_char(char s[], char t[]);

int main(void) {
  char s[20] = "abcd", t[20] = "eblk";
  printf("before : %s \n", s);
  delete_char(s, t);
  printf("after : %s \n", s);
}

void delete_char(char s[], char t[]) {
  int i, j;
  while(s[i] != EOL) {
    for(j = 0; t[j] != EOL;) {
      if(s[i] == t[j]){
        s[i] = SPACE;
        i++; j++;
      }else j++;
    } i++;
  }
}