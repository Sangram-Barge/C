#include <stdio.h>
#define EOFF '\0'

int idx(char source[], char pattern[]) {
  int i, j, k;
  for (i = 0; source[i] != EOFF; i++){
    for (j = i, k = 0; pattern[k] != EOFF && pattern[k] == source[j]; k++, j++);
    if (pattern[k] == EOFF) return i;
  }
  return -1;
}