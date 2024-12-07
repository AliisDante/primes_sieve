#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "sieve.h"

int main(int argc, char *argv[]) {
    uint32_t limit = atoi(argv[1]);

    size_t max_primes;
    if (argc > 2) {
        max_primes = atoi(argv[2]);
    }
    else {
        max_primes = limit;
    }

    uint32_t *primes = malloc(max_primes * sizeof (uint32_t));

    uint32_t length_of_primes = sieve(limit, primes, max_primes);
    for (uint32_t i = 0; i < length_of_primes; ++i) {
        printf("%d\n", primes[i]);
    }

    free(primes);
    return 0;
}
