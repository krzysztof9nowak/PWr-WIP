#include "funs.h"

/*
 algorytm o złożoności O(n*log(n))
*/

int gcd(int x, int y){
    if(x == 0)
        return y;
    return gcd(y % x, x);
}

int phi(int n){
    int wynik = 0;
    for(int i=1; i<=n; i++)
        if(gcd(i,n)==1)
            wynik++;
    return wynik;
}

/*
 alogrytm o złożoności O(n) na podstawie
 https://en.wikipedia.org/wiki/Euler%27s_totient_function#Computing_Euler's_totient_function
*/

// int phi(int n){
//     int wynik = 1;
//     for(int p=2; p<=n; p++){
//         if(n % p == 0){
//             int k = 0;
//             while(n % p == 0){
//                 k++;
//                 n /= p;
//             }
//             for(int i=0; i<(k-1); i++)
//                 wynik *= p;
//             wynik *= (p-1);
//         }
//     }
//     return wynik;
// }


/* 
   algorytm o zlozonosci O(sqrt(n))
   skopiowany z: https://cp-algorithms.com/algebra/phi-function.html
*/

// int phi(int n) {
//     int result = n;
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             while (n % i == 0)
//                 n /= i;
//             result -= result / i;
//         }
//     }
//     if (n > 1)
//         result -= result / n;
//     return result;
// }
