#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long collatz(long n) {
    long count = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        count++;
    }
    return ++count;
}

int main(void) {
    long max = -1;
    long maxI = 0;
    long x;
    for (long i = 14; i < 1000000; i++) {
        x = collatz(i);
        if (x > max) {
            max = x;
            maxI = i;
        }
    }
    printf("%ld\n", maxI);
    return 0;
}