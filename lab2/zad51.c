#include <stdio.h>

int gcd(int a, int b){
  return a==0 ? b : gcd(b%a, a);
}



// zadanie 5 - złożoność obliczeniowa O(n^2)
int main(void){
  long count = 1;
  printf("n;ratio\n");

  for(int n=1; n<=1000; n++){
    for(int i=1; i<n; i++){
      if(gcd(i,n) == 1)
        count += 2;
    }

    double ratio = (double)count / n / n;
    printf("%d;%.10lf\n", n, ratio);
  }

        
  return 0;
}
