#include <stdio.h>

#define MAXIMUM 1000
#define NEWLINE '\n'
#define EOL '\0'

int getl(char* string, int limit);
void copy(char* source, char* location); 

int main() {
  char line[MAXIMUM];
  char save[MAXIMUM];
  int max = 0, linelen;
  while ((linelen = getl(line, MAXIMUM)) > 0) 
    if (linelen > max) {
      max = linelen;
      copy(line, save);
    }
  if (max > 0) 
    printf("%s len is %d\n", save, max);
}

int getl(char* string, int limit) {
  int c, i;
  for(i = 0; i < limit && (c = getchar()) != NEWLINE && c != EOF; ++i) 
    string[i] = c;
  if (c == NEWLINE) 
    string[i++] = c;
  string[i] = EOL;
  return i;
}

void copy(char* source, char* location) {
  int i = 0;
  while((location[i] = source[i]) != EOL)
    i++;
}
