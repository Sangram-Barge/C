#include <stdio.h>

void faranheitToCelcius();
void celciusToFaranheit(); 

int main() {
  celciusToFaranheit();
}

void faranheitToCelcius() {
  int lower = 0, upper = 300, step = 20;
  float celcius, fahr = 0;
  printf("Faranhiet : Celcius\n");
  while (fahr <= upper) {
    celcius = (5.0/9.0) * (fahr - 32);
    printf("%2.2f  %3.3f \n", fahr, celcius);
    fahr += step;
  }
}

void celciusToFaranheit() {
  int lower = 0, upper = 300, step = 20;
  float celcius = 0, faranheit;
  printf("celcius : faranheit \n");
  while(celcius <= upper) {
    faranheit = ((9.0/5.0)*celcius)+32;
    printf("%3.2f %3.2f \n", celcius, faranheit);
    celcius += step;
  }
}