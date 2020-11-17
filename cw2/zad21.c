#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void){
    int N, n=0;
    scanf("%d", &N);
    
    int *arr;
    arr = malloc(sizeof *arr * N);

    int liczba = 2;
    while(n < N){
      bool czy_pierwsza = true;
      for(int i=0; i<n; i++){
        if(liczba % arr[i] == 0){
          czy_pierwsza = false;
          break;
        }
      }

      if(czy_pierwsza){
        printf("%d\n", liczba);
        arr[n] = liczba;
        n++;
      }
      liczba++;
    }


    return 0;
}
