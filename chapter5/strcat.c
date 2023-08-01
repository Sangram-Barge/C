#include <stdio.h>
void strcat(char *target, char *source);
int main(void) {
  char line[500] = "hello this is sangram";
  strcat(line, " hello");
  printf("%s \n", line);
}

void strcat(char *target, char *source) {
  while( *target++ ); --target;
  while ( (*target++ = *source++) );
  *target = '\0';
}
