#include <stdio.h>
#include <string.h>
void reverse(char string[], int len);
int main(void) {
  char string[] = "this is sangram barge";
  printf("original string: %s\n", string);
  reverse(string, strlen(string));
  printf("reversed string: %s\n", string);
}

void reverse(char string[], int len) {
  int start = 0, end = len-1;
  while(start <= end){
    int temp = string[start];
    string[start] = string[end];
    string[end] = temp;
    start++; end--;
  }
}