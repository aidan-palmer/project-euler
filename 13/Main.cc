#include <fstream>
#include <iostream>

using namespace std;

void balance(string& a, string& b) {
    int x = a.size();
    int y = b.size();
    int i;

    if (x > y) {
        for (i = 0; i < x - y; i++) {
            b = "0" + b;
        }
    } else {
        for (i = 0; i < y - x; i++) {
            a = "0" + a;
        }
    }
}

string adder(string a, string b) {
    if (a.empty()){
        return b;
    }
    if (a.size() != b.size()) {
        balance(a, b);
    }
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

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Incorrect usage\n";
        return 1;
    }
    fstream file(argv[1]);

    if (!file) {
        cerr << "Error: file not found.\n";
        return 2;
    }
    string line;
    string sum("");

    while (getline(file, line)) {
        sum = adder(sum, line);
    }
    string ten = sum.substr(0, 10);
    cout << ten << endl;
    return 0;
}