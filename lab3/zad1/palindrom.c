#include "funs.h"

bool palindrom(char napis[]){
    int n = strlen(napis);
    int i = 0; // indeksy lewy
    int j = n - 1; // indeks prawy
    while(i < j){
        if(napis[i] != napis[j])
            return false;
        i++;
        j--;
    }
    return true;
}
