#include <stdio.h>
#define MAXTOP 20
#define EQUALS '='

int stack[MAXTOP], sp = 0;
int push(int val);
void clear();
int pop();
int calculate(char exp[]);
int main(void) {
  char line[] = "1 + 5 = ";
  printf("%c\n",calculate(line));
}

int calculate(char exp[]) {
  int i, num;
  for(i = 0; (num = exp[i]) != EQUALS; i++){
    if (num == '+') push(exp[++i] + pop());
    else push(num);
  }
  return (push(pop()));
}

int push(int val){
  if(sp < MAXTOP)return stack[sp++] = val;
  printf("error stack full\n");
  clear();
  return 0;
}

int pop(){
  if(sp > 0) return stack[--sp];
  else {
    printf("error stack full\n");
    clear();
    return 0;
  }
}

void clear(){
  sp = 0;
}
