#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

struct primeNode {
		mpz_t value;
		struct primeNode *next;
};

int main(int argc, char **argv) {
	struct primeNode *primesStart = calloc(1, sizeof(struct primeNode));
	struct primeNode *primesEnd = primesStart;
	mpz_t currentNum;
	mpz_init(currentNum);
	mpz_init(primesStart->value);
	mpz_set_ui(primesStart->value, 2);
	mpz_out_raw(stdout, primesStart->value);
	primesEnd->next = NULL;
	mpz_set_ui(currentNum, 3);
	mpz_t square;
	mpz_init(square);
	mpz_t modulus;
	mpz_init(modulus);
	for (;;) {
		struct primeNode *currentNode = primesStart->next;
		mpz_set_ui(square, 0);
		int isPrime = 1;
		while (isPrime && currentNode != NULL && currentNode->next != NULL && mpz_cmp(square, currentNum) <= 0) {
			mpz_mod(modulus, currentNum, currentNode->value);
			if (mpz_cmp_ui(modulus, 0) == 0) isPrime = 0;
			currentNode = currentNode->next;
			mpz_mul(square, currentNode->value, currentNode->value);
		}
		if (isPrime) {
			primesEnd->next = calloc(1, sizeof(struct primeNode));
			mpz_init(primesEnd->next->value);
			mpz_set(primesEnd->next->value, currentNum);
			mpz_out_raw(stdout, currentNum);
			primesEnd = primesEnd->next;
		}
		mpz_add_ui(currentNum, currentNum, 2);
	}
	primesEnd = primesStart;
	while (primesEnd != NULL) {
		struct primeNode *temp = primesEnd->next;
		free(primesEnd);
		primesEnd = temp;
	}
	return 0;
}
