#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 128

void printBN(char *msg, BIGNUM * a)
{
    /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
    char * number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main(void) {

    BN_CTX *ctx = BN_CTX_new(); // init ctx struct for BIGNUM temp variables

    // 3 primes p,q,e
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();

    BN_hex2bn(&p, 'F7E75FDC469067FFDC4E847C51F452DF');
    BN_hex2bn(&q, 'E85CED54AF57E53E092113E62F436F4F');
    BN_hex2bn(&e, '0D88C3');

    BIGNUM *n = BN_new();
    BN_mul(n, p, q, ctx); // n = p*q

    BIGNUM *phi = BN_new();
    BIGNUM *phi_p = BN_new();
    BIGNUM *phi_q = BN_new();
    BN_sub(phi_p, p, 1); // phi_p = p - 1
    BN_sub(phi_q, q, 1); // phi_q = q - 1
    BN_mul(phi, phi_p, phi_q, ctx); // Euler's totient function φ = (p-1) * (q-1)


    // Public key is (e, n) - find (d, n)

    return 0;
}