#include <stdio.h>

int main() {
  int lower = 0, upper = 300, step = 20;
  float celcius, fahr = 0;
  while (fahr <= upper) {
    celcius = (5.0/9.0) * (fahr - 32);
    printf("%3.2f fahranhiet = %3.3f celcius \n", fahr, celcius);
    fahr += step;
  }
}