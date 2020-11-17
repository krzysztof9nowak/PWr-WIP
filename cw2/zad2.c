#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    int n;
    scanf("%d", &n);
    
    bool *arr;
    arr = malloc(sizeof *arr * n);
    memset(arr, true, n);

    arr[0] = false;
    arr[1] = false;

    // sito Erastotenesa
    for(int i=2; i<n;i++){
        if(arr[i]){
            printf("%d\n", i);
            for(int j=i; j<n; j+=i)
                arr[j] = false;
        }
    }
    return 0;
}
