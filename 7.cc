#include <iostream>
#include <climits>

using namespace std;

bool is_prime(int n) {
    int div = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            div++;
        }
    }
    return div < 3;
}

int main(void) {
    int count = 0;

    for (int i = 2; i < INT_MAX; i++) {
        if (is_prime(i)) {
            count++;

            if (count == 10001) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}