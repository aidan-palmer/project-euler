#include <iostream>
#include <vector>

using namespace std;

int num_divisors(int n) {
    int count = 1;
    int i = 2;
    int exp;

    while (i * i <= n) {
        exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        if (exp > 0) {
            count *= exp + 1;
        }
        i++;
    }
    if (n > 1) {
        count *= 2;
    }
    return count;
}

int tri_num() {
    int last_num = 28;

    for (int i = 8; i < INT32_MAX; i++) {
        last_num += i;

        if (num_divisors(last_num) > 500) {
            return last_num;
        }
    }
    return -1;
}

int main(void) {
    cout << tri_num() << endl;
    return 0;
}