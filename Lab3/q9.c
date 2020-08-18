#include <stdio.h>
#include <limits.h>
#include <math.h>

int modInverse(long int a, long int m) 
{ 
    for (long int x=1; x<m; x++) {
        if ((x > 1000000) && (x % 1000000 == 0)) {
            printf("%ld\n", x);
        }

        if ((a*x) % m == 1) {
           return x; 
        }
    }
} 

int main(void) {

    long int n = 44428782786092197;
    long int e = 1039;

    long int p, q;

    for(int i = floor(sqrt(n)); i < INT_MAX; i++) {
        if(n % i == 0) {
            p = i;
            printf("FOUND P: %ld\n", p);
            break;
        }
    }

    q = n / p;
    printf("FOUND Q: %ld\n", q);


    long int phi = (p-1) * (q-1);
    printf("phi: %ld\n", phi);


    return 0;
}