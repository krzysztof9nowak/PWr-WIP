#include <stdio.h>

#define N 1000

int main(void){
  int sigma[N+1] = {0};

  printf("Liczby doskonałe:\n");
  for(int n=1; n<N; n++){
    for(int k=1; (2*k <= n) && (k<n); k++){
      if(n % k == 0)
        sigma[n] += k;
    }
    if(sigma[n] == n)
      printf("%d\n", n);
  }
  
  printf("Pary zaprzyjaźnione:\n");
  for(int n=1; n<N; n++){
    int m = sigma[n];
    if(m <= n)
      continue;
    if(m >= N)
      continue;
    if(sigma[m] == n)
      printf("%d %d\n", n, m);
  }
  return 0;
}

