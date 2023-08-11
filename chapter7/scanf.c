#include <stdio.h>

int main() {
  int age;
  float height;
  char name[50];
  printf("enter name, age, height\n");
  scanf("%s %d %f", name, &age, &height);
  printf("\nname : %s\nage : %d\nheight : %f\n", name, age, height);
}
