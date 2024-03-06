#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <Windows.h>
#include <conio.h>

using namespace std;

const int ROWS1 = 5;
const int COLS1 = 10;
const int ROWS2 = 5;
const int COLS2 = 5;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array1[ROWS1][COLS1];
    int array2[ROWS2][COLS2];

    
    srand(time(nullptr));

    
    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            array1[i][j] = rand() % 51; 
        }
    }

    
    for (int i = 0; i < ROWS2; ++i) {
        for (int j = 0; j < COLS2; ++j) {
            array2[i][j] = array1[i][2 * j] + array1[i][2 * j + 1]; 
        }
    }

   
    cout << "Перший масив:" << endl;
    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            cout << array1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Другий масив:" << endl;
    for (int i = 0; i < ROWS2; ++i) {
        for (int j = 0; j < COLS2; ++j) {
            cout << array2[i][j] << " ";
        }
        cout << endl;
    }
    _getch();
    return 0;
}
