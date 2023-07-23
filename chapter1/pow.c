#include <stdio.h>

void test(char*);

int main() {
  test("hello");
}
void test(char* name){ 
  printf("%s", name);
}