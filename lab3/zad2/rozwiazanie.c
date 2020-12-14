#include "funs.h"
#include <stdio.h>

double rozwiazanie(double (*func)(double), double a, double b, double eps){
    double c = (a+b) / 2.0;
    if(fabs(a-b) / 2.0 <= eps)
        return c;

    if((*func)(a) * (*func)(c) <= 0)
        return rozwiazanie(func, a, c, eps);
    else if((*func)(c) * (*func)(b) <= 0)
        return rozwiazanie(func, c, b, eps);
    else{
        printf("Brak rozwiazania na przedziale [%.3lf, %.3lf]\n",a,b);
        return 0;
    }
}
