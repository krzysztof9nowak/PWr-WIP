#include <stdio.h>
#include <assert.h>


#define LEN(x) (sizeof(x)/sizeof(x[0]))

int main(void){
  const int banknoty[5] = {200, 100, 50, 20, 10};
  const int n_banknoty = LEN(banknoty);
  const int monety_zl[3] = {5, 2, 1};
  const int n_monety_zl = LEN(monety_zl);
  const int monety_gr[6] = {50, 20, 10, 5, 2, 1};
  const int n_monety_gr = LEN(monety_gr);
  
  int kwota_zl, kwota_gr;
  printf("podaj liczbę złotych: ");
  scanf("%d", &kwota_zl);
  printf("podaj liczbę groszy: ");
  scanf("%d", &kwota_gr);
  assert(kwota_zl >= 0);
  assert(kwota_gr >= 0);
  assert(kwota_gr < 100);

  printf("banknoty: \n");
  for(int i = 0; i<n_banknoty; i++){
    int nominal = banknoty[i];
    int liczba = kwota_zl / nominal;
    kwota_zl -= nominal * liczba;
    if(liczba)
      printf("\t%d x %d zł\n", liczba, nominal);
  }

  printf("monety: \n");
  for(int i = 0; i<n_monety_zl; i++){
    int nominal = monety_zl[i];
    int liczba = kwota_zl / nominal;
    kwota_zl -= nominal * liczba;
    if(liczba)
      printf("\t%d x %d zł\n", liczba, nominal);
  }

  for(int i = 0; i<n_monety_gr; i++){
    int nominal = monety_gr[i];
    int liczba = kwota_gr / nominal;
    kwota_gr -= nominal * liczba;
    if(liczba)
      printf("\t%d x %d gr\n", liczba, nominal);
  }
  return 0;
}
