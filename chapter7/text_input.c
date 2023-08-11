#include <stdio.h>
#include "../lib/get_line.c"

int main() {
  char line[1000];
  int len = get_line(line, 1000);
  printf("%s\n", line);
}
