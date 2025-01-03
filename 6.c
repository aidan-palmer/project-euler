#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define LIM 100

int sum_square() {
    int sum = 0;

    for (int i = 1; i <= LIM; i++) {
        sum += i * i;
    }
    return sum;
}

int square_sum() {
    int sum = 0;

    for (int i = 1; i <= LIM; i++) {
        sum += i;
    }
    return sum * sum;
}

int main(void) {
    printf("%d\n", square_sum() - sum_square());
    return 0;
}