#include <stdio.h>

int main(void){
  const int len = 11;
  char word[12] = "ABRAKADABRA";
  
  for(int i=len-1; i >= 0; i--){
    for(int j=i; j<len-1; j++)
      printf(" ");
    for(int j=0; j<i; j++)
      printf("%c ", j[word]); 
    printf("\n");
  }

  return 0;
}
