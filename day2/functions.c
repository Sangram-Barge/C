#include <stdio.h>
#include <stdlib.h>
void sayHi();
void greet(char name[]);

int main() {
  sayHi();
  greet("sangram");
  return 0;
}

void greet(char name[]) {
  printf("hello %s\n", name);
  return;
}

void sayHi() {
  printf("hello from the function \n");
  return;
}