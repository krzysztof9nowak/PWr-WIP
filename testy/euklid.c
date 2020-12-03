#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){
  return true;
  if(n <= 3)
    return n > 1;
  if((n%2==0) || (n%3==0))
    return false;
  int i=5;
  while (i*i <= n){
    if ((n%i == 0) || (n%(i+2) == 0))
      return false;
    i += 6;
  }
  return true;
}

int main(){
  for(long n=0;n<10;n++){
    for(long k=0;k<=n;k++){
      printf("%ld %ld\n",n,k);
      long common = (1 << k) + 1;
      long p = common * (1 << (n+1-k)) - 1;
      if(!is_prime(p))
        continue;
      long q = common * (1 << (n+1)) - 1;
      if(!is_prime(q))
        continue;
      long r = common * common * (1 << (2*n+2-k)) - 1;
      if(!is_prime(r))
        continue;
      long a = (1 << (n + 1)) * p * q;
      long b = (1 << (n+1)) * r;
      printf("%ld %ld\n",a,b);
    }
  }
}

