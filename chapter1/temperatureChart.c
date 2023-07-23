#include <stdio.h>

int main() {
  int lower = 0, upper = 300, step = 20;
  float celcius, fahr = 0;
  printf("Faranhiet : Celcius\n");
  while (fahr <= upper) {
    celcius = (5.0/9.0) * (fahr - 32);
    printf("%2.2f  %3.3f \n", fahr, celcius);
    fahr += step;
  }
}