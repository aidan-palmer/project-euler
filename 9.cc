#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;

    for (a = 1; a < 1000; a++) {
        for (b = a + 1; b < 1000; b++) {
            for (c = b + 1; c < 1000; c++) {
                if (a * a + b * b == c * c && a + b + c == 1000) {
                    cout << a * b * c << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}