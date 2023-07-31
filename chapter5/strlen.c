#include <stdio.h>
int str_len(char *s);
int main(void) {
  int len;
  char string[] = "this is sangram barge";
  len = str_len(string);
  printf("%d\n", len);
}

int str_len(char *s) {
  int i;
  for(i = 0; *s != '\0'; s++)
    i++;
  return i;
}
