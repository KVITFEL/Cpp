#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<vector<int>>& arr);

void generateArray(int n) {
    vector<vector<int>> A(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == n - 1) {
                A[i][j] = 1;
            }
            else if (i + j > n - 1) {
                A[i][j] = 2;
            }
        }
    }

    // Вызов функции для вывода массива A
    printArray(A);
}

void printArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    generateArray(n);

    return 0;
}
