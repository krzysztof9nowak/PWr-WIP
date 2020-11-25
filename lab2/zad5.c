#include <stdio.h>

int gcd(int a, int b){
  return a==0 ? b : gcd(b%a, a);
}


// zadanie 5 - lujowa zlozonosc obliczeniowa O(n^3), polecam zad51.c
int main(void){
  printf("n;ratio\n");

  for(int n=1; n<=1000; n++){
    long count = 0;
    for(int a=1; a<=n; a++){
      for(int b=1; b<=n; b++){
        if(gcd(a,b) == 1)
          count++;
      }
    }
    double ratio = (double)count / n / n;
    printf("%d;%.10lf\n", n, ratio);
  }

        
  return 0;
}
