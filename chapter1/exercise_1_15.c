#include <stdio.h>

#define MAXIMUM 1000
#define NEWLINE '\n'
#define EOL '\0'

int getl(char* string, int limit);
void append(char* source, char* value); 

int main() {
  char line[MAXIMUM];
  char save[MAXIMUM];
  save[0] = EOL;
  int linelen;
  while ((linelen = getl(line, MAXIMUM)) > 0) {
    if (linelen > 80) 
      append(save, line);
  }
  printf("%s\n", save);
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

void append(char* source, char* value) {
  int i;
  for(i = 0; source[i] != EOL; ++i);
  while((source[i] = value[i]) != EOL) ++i;
  source[i] = EOL;
}
