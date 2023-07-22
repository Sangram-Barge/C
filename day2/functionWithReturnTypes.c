#include <stdio.h>
#include <stdlib.h>

int cube(int a);

int main() {
  int a;
  printf("Enter the number you want to cube : ");
  scanf("%d",&a);
  printf("cube of %d is : %d \n", a, cube(a));
}

int cube(int a){
  return a * a * a;
}