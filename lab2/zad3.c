#include <stdio.h>

int main(void){
  double sum = 0;
  int n=0;

  while(!(sum > 10)){
    n++;
    sum += 1.0/n;
  }
  printf("%d\n", n);

  return 0;
}
