#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
int n;

int right(int i, int j) {
    if (j + 3 >= n) {
        return 0;
    }
    int product = 1;

    for (int k = j; k < j + 4; k++) {
        product *= matrix[i][k];
    }
    return product;
}

int down(int i, int j) {
    if (i + 3 >= n) {
        return 0;
    }
    int product = 1;

    for (int k = i; k < i + 4; k++) {
        product *= matrix[k][j];
    }
    return product;
}

int leftDiag(int i, int j) {
    if (i + 3 >= n || j - 3 < 0) {
        return 0;
    }
    int product = 1;

    for (int k = i, l = j; k < i + 4; k++, l--) {
        product *= matrix[k][l];
    }
    return product;
}

int rightDiag(int i, int j) {
    if (i + 3 >= n || j + 3 >= n) {
        return 0;
    }
    int product = 1;

    for (int k = i, l = j; k < i + 4; k++, l++) {
        product *= matrix[k][l];
    }
    return product;
}

int greatest() {
    int max = -1;
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int prods[4] = {right(i, j), down(i, j), leftDiag(i, j), rightDiag(i, j)};
            for (k = 0; k < 4; k++) {
                if (prods[k] > max) {
                    max = prods[k];
                }
            }
        }
    }
    return max;
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
    string token;

    while (getline(file, line)) {
        stringstream stream(line);
        vector<int> arr;

        while (getline(stream, token, ' ')) {
            arr.push_back(stoi(token));
        }
        matrix.push_back(arr);
    }
    n = matrix.size();
    cout << greatest() << endl;
    return 0;
}