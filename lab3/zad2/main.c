#include <stdio.h>
#include "funs.h"

int main(){
    for(double eps=0.1; eps >= 1e-8; eps /= 10.0){
        double x = rozwiazanie(&f_badana, 2, 4, eps);
        printf("log10(eps): %.2lf, x: %.10lf\n", log10(eps), x);
    }
    return 0;
}
