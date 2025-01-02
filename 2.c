#include <stdio.h>

int main(void) {
    int sum = 0;
    int val = 2;
    int prev_1 = 1;
    int prev_2 = 2;

    while (val <= 4000000) {
        if (val % 2 == 0) {
            sum += val;
        }
        val = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = val;

        //printf("%d\n", val);
    }
    printf("%d\n", sum);
    return 0;
}