#include <stdio.h>
#include <stdlib.h>

int main() {
  int numbers[] = {1, 4, 6, 109, 23, 45, 23, 867};
  int numbers2[10];
  printf("number at first place is : %d \n", numbers[0]);
  printf("number at first place by ptr is : %d \n", *numbers);

  printf("number at fourth place is : %d \n", numbers[3]);
  printf("number at fourth place by ptr is : %d \n", *(numbers+3));

  numbers2[3] = 78;
  printf("number at fourth place by ptr is : %d \n", *(numbers2+3));
  printf("number at first place by ptr is : %d \n", *(numbers2+2));

  return 0;
}