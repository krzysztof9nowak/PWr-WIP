#include <stdio.h>

int main(void){
  printf("(*) christmass tree. Enter number of rows: ");
  int n;
  scanf("%d", &n);
  for(int row=0; row<n; row++){
    int no_spaces = n - 1 - row;
    int no_stars = 1 + 2*row;

    for(int i=0; i<no_spaces; i++)
      printf(" ");
    for(int i=0; i<no_stars; i++)
      printf("*");
    printf("\n");
  }
  return 0;
}
