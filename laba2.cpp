#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int L, M, sum;
    cout << "Введите размеры матрицы:" << endl;
    cout << "L = ";
    cin >> L; //строки матрицы
    cout << "M = ";
    cin >> M; //столбцы матрицы
    double** Q = new double* [L];
    for (int i = 0; i < L; i++)
    {
        Q[i] = new double[M];
    }
    cout << "Введите матрицу:" << endl;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Q[i][j]; //элементы матрицы
        }
    }
    cout << "Вводимая матрица:" << endl;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
            cout << Q[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    cout << "Искомая матрица:" << endl;
    for (int i = 0; i < L; i++)
    {
        sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += Q[i][j]; //сумма элементов каждой строки
        }
        for (int j = 0; j < M; j++)
        {
            Q[i][j] -= (double)sum / M; //среднее арифметическое
            cout.precision(2);
            cout << fixed << Q[i][j] << " "; 
        }
        cout << endl; //Переходим на новую строку
    }

    
} 
