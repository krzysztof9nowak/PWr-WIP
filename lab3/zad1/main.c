#include <stdio.h>
#include "palindrom.h"

void testuj(char napis[]){
    printf("\"%s\"", napis);
    if(palindrom(napis))
        printf(" to palindrom\n");
    else
        printf(" to nie palindrom\n");
}


int main(){
    testuj("ala");
    testuj("");
    testuj("krowa");
    testuj("abba");
    testuj("abab");
    return 0;
}
