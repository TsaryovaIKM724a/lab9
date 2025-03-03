#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, m;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> n >> m;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    bool Symmetric = (n == m);
    if (Symmetric) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    Symmetric = false;
                    break;
                }
            }
            if (!Symmetric) break;
        }
    }

    if (Symmetric)
        cout << "Матрица симметрична.\n";
    else
        cout << "Матрица не симметрична.\n";

    int* chet = new int[n];

    for (int i = 0; i < n; i++) {
        chet[i] = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 == 0)
                chet[i]++;
        }
    }

    cout << "Количество чётных элементов в каждой строке: ";
    for (int i = 0; i < n; i++) {
        cout << chet[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] chet;
}
