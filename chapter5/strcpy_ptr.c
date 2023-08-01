#include <stdio.h>
void stringcpy(char *target, char *source);
int main(void) {
  char source[] = "this is sangram ";
  char target[] = "                ";
  printf("%s, %s\n", source, target);
  stringcpy(target, source);
  printf("%s, %s\n", source, target);
}

void stringcpy(char *target, char *source) {
  while( (*target++ = *source++) );
}
