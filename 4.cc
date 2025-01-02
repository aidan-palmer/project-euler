#include <iostream>
#include <queue>

using namespace std;

bool is_palindrome(int n) {
    string s = to_string(n);
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++; 
        j--;
    }
    return true;
}

int main(void) {
    priority_queue<int> palindromes;

    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            if (is_palindrome(i * j)) {
                palindromes.push(i * j);
            }
        }
    }
    cout << palindromes.top() << endl;
    return 0;
}