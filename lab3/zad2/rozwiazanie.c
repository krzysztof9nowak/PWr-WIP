#include "funs.h"
#include <stdio.h>
#include <assert.h>

double rozwiazanie(double (*func)(double), double a, double b, double eps){
    assert((*func)(a) * (*func)(b) <= 0); // this method can't find roots on [a, b] interval

    double c = (a+b) / 2.0;
    if(fabs(a-b) / 2.0 <= eps)
        return c;

    if((*func)(a) * (*func)(c) <= 0)
        return rozwiazanie(func, a, c, eps);
    else
        return rozwiazanie(func, c, b, eps);
}
