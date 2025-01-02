#include <iostream>
#include <vector>

using namespace std;

vector<long> prime_factors(long num) {
    vector<long> results;

    while (num % 2 == 0) {
        num /= 2;
    }

    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            results.push_back(i);
            num /= i;
        }
    }
    if (num > 2) {
        results.push_back(num);
    }
    return results;
}

int main(void) {
    vector<long> factors = prime_factors(600851475143);
    cout << factors[factors.size() - 1] << endl;
    return 0;    
}