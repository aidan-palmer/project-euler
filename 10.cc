#include <iostream>

using namespace std;

#define LIM 2000000

bool is_prime(int n) {
    int div = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div++;
        }
        if (div > 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    long sum = 0, i;

    for (i = 2; i < LIM; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}