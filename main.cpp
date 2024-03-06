#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int rows = 3;
    const int cols = 4;

    int array[rows][cols] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int row_sum[rows] = { 0 };
    int col_sum[cols] = { 0 };
    int total_sum = 0;

   
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            row_sum[i] += array[i][j];
            total_sum += array[i][j];
        }
    }

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            col_sum[j] += array[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << "  ";
        }
        cout << "| " << row_sum[i] << endl;
    }

    cout << "--------------------" << endl;

    
    for (int j = 0; j < cols; ++j) {
        cout << col_sum[j] << "  ";
    }
    cout << "| " << total_sum << endl;

    _getch();
    return 0;
}
