#include <stdio.h>

int main(void){
  printf("podaj n: ");
  int n;
  scanf("%d", &n);
  double avg = 0;
  for(int i=0; i<n; i++){
    double buf;
    scanf("%lf", &buf);
    avg += buf / n;
  }
  printf("Srednia wynosi: %lf\n", avg); 
  return 0;
}
