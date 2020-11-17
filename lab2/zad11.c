#include <stdio.h>
#include <assert.h>


int main(void){
  const int nominaly[] = {20000, 10000, 5000, 2000, 1000, 
    500, 200, 100, 50, 20, 10, 5, 2, 1}; // nominaly monet i banktow w gr, malejaco
  const int n_nominaly = (sizeof(nominaly)/sizeof(nominaly[0]));
  const int najwieksza_moneta = 500; //najwiekszy nominal monety wynosi 5zl = 500gr
  
  int zl, gr;
  printf("podaj liczbę złotych: ");
  scanf("%d", &zl);
  printf("podaj liczbę groszy: ");
  scanf("%d", &gr);
  assert(zl >= 0);
  assert(gr >= 0);
  
  gr += 100 * zl;

  printf("banknoty: \n");
  for(int i = 0; i<n_nominaly; i++){
    int nominal = nominaly[i];
    if(nominal == najwieksza_moneta)
      printf("monety: \n");
    int liczba = gr / nominal;
    gr -= nominal * liczba;
    if(liczba){
      if(nominal >= 100)
        printf("\t%d x %d zł\n", liczba, nominal / 100);
      else
        printf("\t%d x %d gr\n", liczba, nominal);
    }
  }
  return 0;
}
