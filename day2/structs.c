#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
  char name[30];
  char company[20];
  int age;
};


int main() {
  struct Employee emp;
  emp.age = 25;
  printf(emp.age);
}