#include<stdio.h>
double atof(char s[]);
int main(void) {
  printf("string : %s atof : %f\n", "1022.12", atof("1022.12"));
  return 0;
}

double atof(char s[]) {
  int i, sign;
  double val, power;
  for(i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++);
  sign = 1;
  if (s[i] == '+' || s[i] == '-')
    sign = s[i] == '+' ? 1 : -1;
  for (val = 0; s[i] >= '0' && s[i] <= '9'; i++) 
    val = val * 10 + s[i] - '0';
  if (s[i] == '.') i++;
  for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
    val = val * 10 + s[i] - '0';
    power *= 10;
  }
  return (sign * val / power);
}
