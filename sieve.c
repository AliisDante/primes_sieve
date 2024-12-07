#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2) {
        return 0;
    }
    // The index must allow up until the limit, so the size must be minimally limit + 1
    uint32_t *number_line = malloc((limit+1) * sizeof (uint32_t));
    // uint32_t number_line[limit+1];
    if (number_line == NULL) {
        printf("Insufficient Memory!");
        return 0;
    }

    // Set all values except 0 and 1 to false
    memset(number_line+2, 1, (limit - 1) * sizeof (uint32_t));
    number_line[0] = 0;
    number_line[1] = 0;

    for (uint32_t i = 2; i <= limit; ++i) {
        if (number_line[i]) {
            number_line[i] = 1;
            uint32_t next_multiple = i * 2;
            while (next_multiple <= limit) {
                number_line[next_multiple] = 0;
                next_multiple += i;
            }
        }
    }

    size_t length_of_primes = 0;
    for (uint32_t i = 0; i <= limit; ++i) {
        if (number_line[i] && (length_of_primes < max_primes)) {
            primes[length_of_primes] = i;
            ++length_of_primes;
        }
    }

    free(number_line);

    return length_of_primes;
}
