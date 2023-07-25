#include <stdio.h>
#define MAXCHAR 10
void squeez(char[], char);

int main(void) {
  char line[10] = "thisissad", c = 's';
  printf("line %s before squeezing %c\n", line, c);
  squeez(line, c);
  printf("line %s after squeezing %c \n", line, c);
  return 0;
}

void squeez(char line[], char c){
  int i, j; 
  for(i = 0,j = 0; line[i] != '\0'; i++) 
    if(line[i] != c) 
      line[j++] = line[i];
  line[j] = '\0';
}