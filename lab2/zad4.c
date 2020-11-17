#include <stdio.h>
#include <math.h>

int main(void){
  int N = 1000;
  double output = 1;

  for(int n=1;n<=N;n++)
    output *= pow((double)n, 0.001);
  
  printf("%lf\n", output); 
  return 0;
}
