#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool is_divisible(int n, int upper_bound) {
    for (int i = 2; i <= upper_bound; i++) {
        if (n % i != 0) {
            return false;
        }
    }
    return true;
}

int smallest_divisible(int upper_bound) {
    for (int i = 1; i < INT_MAX; i++) {
        if (is_divisible(i, upper_bound)) {
            return i;
        }
    }
    return -1;
}   

int main(void) {
    printf("%d\n", smallest_divisible(20));
    return 0;
}