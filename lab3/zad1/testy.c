#include <stdio.h>
#include "funs.h"

void testuj(char napis[]){
    printf("\"%s\"", napis);
    if(palindrom(napis))
        printf(" to palindrom\n");
    else
        printf(" to nie palindrom\n");
}
