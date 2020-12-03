#include <stdio.h>


int a[] = {1,2,3,4,5};
int b[] = {1,2,2,10,15};

#define LEN_A (int)(sizeof(a) / sizeof(a[0]))
#define LEN_B (int)(sizeof(b) / sizeof(b[0]))

int c[LEN_A + LEN_B];


int main(){
  int n=0,m=0;
  while((n+m)<(LEN_A+LEN_B)){
    if((m == LEN_B) || ((n<LEN_A) && (a[n] < b[m]))){
      c[n+m] = a[n];
      n++;
    } else {
      c[n+m] = b[m];
      m++;
    }
    printf("%d\n", c[n+m-1]);
  }
}
