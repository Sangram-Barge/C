#include <stdio.h>
#define HYPHEN '-'
void expand(char s1[], char s2[]);
int main(void) {
 char s1[1000] = "hello a-c 0-3\n", s2[1000];
 expand(s1, s2);
 printf("before : %safter : %s\n", s1, s2);
}
void expand(char s1[], char s2[]) {
  int i, j, count;
  i = j = count = 0;
  while(s1[i] != '\n') {
    count++;
    if (s1[i] != HYPHEN){ 
      s2[j++] = s1[i++];
    }
    else{ 
      for(int c = s1[i-1]+1; c <= s1[i+1]; ++c) 
        s2[j++] = c;
      i+=2;
    }
    s2[j] = EOF;
  }
}