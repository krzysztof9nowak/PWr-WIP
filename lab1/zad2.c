#include <stdio.h>
#include <math.h>

int main(void){
  printf("Quadratic solver\na*x^2 + b*x + c = 0\nEnter a, b and c coefficients seperated with spaces\n" );
  double a,b,c;
  scanf("%lf %lf %lf", &a, &b, &c);
  if(a == 0){
    printf("It's not a quadratic! Solving linear eq\n");
    double x = -c/b;
    printf("Eq has one root x=%f\n",x); 
    return 0;
  }
  double discriminant = b*b - 4*a*c;
  if(discriminant < 0){
    printf("There are no real roots\n");
    return 0;
  } 
  if(discriminant == 0){
    double x = -b / (2*a);
    printf("Eq has one root. x=%f\n", x);
    return 0;
  }
  // discriminant > 0
  double x_0 = (-b - sqrt(discriminant)) / (2*a);
  double x_1 = (-b + sqrt(discriminant)) / (2*a);
  printf("Eq has two real roots, x_0=%f, x_1=%f\n", x_0, x_1);
  return 0;
}
