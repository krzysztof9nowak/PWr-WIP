#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define N 1000000000

bool sito[N];
int main(){
  double wspl_pierwszosci = 1.0;
  double last=0;
  for(int i=0;i<N;i++)
    sito[i] = true;

  for(int i=2; i<N; i++){
    if(sito[i]){
      wspl_pierwszosci *= (1.0 - 1.0 / i / i);
      if(wspl_pierwszosci == last)
        break;
      last = wspl_pierwszosci;
      for(int j=i;j<N; j+=i)
        sito[j] = false;
    }
  }
  printf("%.30lf\n", wspl_pierwszosci);

  return 0;
}
