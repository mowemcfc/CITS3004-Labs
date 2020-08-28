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

// Public key is (e, n) - private key is (d, n)

void decrypt_message(BIGNUM *C, BIGNUM *e, BIGNUM *n, BIGNUM *d) {

    return;
}

void encrypt_message(BIGNUM *msg, BIGNUM *e, BIGNUM *n, BIGNUM *a) {

    return;
}

int main(void) {

    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *msg = BN_new(); // original input message
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();


    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    BN_hex2bn(&msg, "4120746f702073656372657421");

    BIGNUM *ct = BN_new(); // encrypted message
    BIGNUM *pt = BN_new(); // decrypted message

    BN_mod_exp(ct, msg, e, n, ctx);
    printBN("encrypted message: ", ct);

    BN_hex2bn(&ct, "24C89C26F6DA860963AF6A6CC6335ED8176A71BADF4771C7726D09E66A6BE4AB");

    BN_mod_exp(pt, ct, d, n, ctx);
    printBN("decrypted message: ", pt);

}