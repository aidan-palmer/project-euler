#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

uint64_t binomial_coefficient(int n) {
    uint64_t result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (n + i);
        result /= i;
    }
    return result;
}

int main(void) {
    int n = 20;
    uint64_t solution = binomial_coefficient(n);
    printf("%lu\n", solution);
    return 0;
}