#include <iostream>

using namespace std;

string adder(string a, string b) {
    int carry = 0;
    int sum;
    for (int i = a.size() - 1; i >= 0; i--) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
            a[i] = sum + '0';
        } else {
            carry = 0;
            a[i] = sum + '0';
        }
    }
    if (carry) {
        a = "1" + a;
    }
    return a;
}

string power(string base, int n) {
    for (int i = 1; i < n; i++) {
        base = adder(base, base);
    }
    return base;
}

size_t sum(string s) {
    size_t result = 0;
    for (char c : s) {
        result += c - '0';
    }
    return result;
}

int main(void) {
    cout << sum(power("2", 1000)) << endl;
    return 0;
}