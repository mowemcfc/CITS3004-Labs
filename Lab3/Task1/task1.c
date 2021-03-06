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

    BIGNUM *M = BN_new(); // q9 - message to be signed
    BIGNUM *S = BN_new(); // q9 - signed hex value

    // Public key is (e, n) - find (d, n) via computing modular inverse
    BIGNUM *d = BN_new();
    BIGNUM *n = BN_new();

    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");
    BN_hex2bn(&M, "49206F776520796F75202432303030");
    
    BN_mul(n, p, q, ctx); // n = p*q
    printBN("n is: ", n);

    BIGNUM *phi = BN_new();
    BN_sub_word(p, (BN_ULONG) 1); // p = p - 1
    BN_sub_word(q, (BN_ULONG) 1); // q = q - 1
    BN_mul(phi, p, q, ctx); // Euler's totient function φ = (p-1) * (q-1)
    printBN("phi is: ", phi);

    BN_mod_inverse(d, e, phi, ctx);
    printBN("d is: ", d);


    BN_mod_exp(S, M, d, n, ctx); // q9 -  S(M) = M^d % n
    printBN("S is:", S);


/*
    BN_mod_exp(M, s, e, n, ctx);

    printBN("s: ", s);
    printBN("M: ", M);

    BIGNUM *ct = BN_new();
    BIGNUM *pt = BN_new();

    BN_mod_exp(ct, msg, e, n, ctx);
    printBN("encrypted message: ", ct);

    BN_mod_exp(pt, ct, d, n, ctx);
    printBN("decrypted message: ", pt);
*/



    return 0;
}