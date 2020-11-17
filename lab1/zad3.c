#include <stdio.h>
#include <assert.h>

int main(void){
  int n;
  printf("(*) rectangle drawing tool. Enter n: ");
  scanf("%d", &n);
  assert(n > 0 && n<=20);
  for(int i=0; i<n; i++){
    for(int j=0; j<(2*n); j++)
      printf("*");
    printf("\n");
  }
  return 0;
}
