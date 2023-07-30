#include <stdio.h>
#define MAXTOP 20
int stack[MAXTOP], sp = 0;
int push(int val);
void clear();
int pop();
int main(void) {
  
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
