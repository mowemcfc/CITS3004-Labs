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

    BIGNUM *s = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM* M = BN_new();


    BN_hex2bn(&s, "345B2AD16ED459EC90E92C4402384CF126CEE0693DB3CEAA5E1165CC02FA4F0F");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");


    BN_mod_exp(M, s, e, n, ctx);

    printBN("M: ", M);
    return 0;
}