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
    int total_sum = 0;
    int x = 0;
    int max = 0;
    int min = array[1][1];
    

    // загальна сума
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            total_sum += array[i][j];

        }
    }
    
    // середне аріфметичне
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            x += 1;
        }
    }

    //мінімальне
    

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    cout << "Загальна сума " << total_sum << endl;
    cout << "Середне аріфметичне " << total_sum/x << endl;
    cout << "Найменьше з масиву " << min << endl;
    cout << "Найбільше з масиву " << max << endl;

    _getch();
    return 0;
}
