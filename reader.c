#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char **argv) {
    mpz_t temp;
    mpz_init(temp);
    while (mpz_inp_raw(temp, stdin) != 0) {
        mpz_out_str(stdout, 10, temp);
        putchar('\n');
    }
    return 0;
}
