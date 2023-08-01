#include <stdio.h>
#include "alloc_free.h"
#define STRCPY(target, source) while((*target++ = *source++))
int main() {
  char *line = alloc(20);
  char *cline = alloc(20);
  line = "hello";
  while((*cline++ = *line++));
  printf("%s : %s \n", line, cline);
}
