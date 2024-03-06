#include <iostream>
#include <Windows.h>
#include <cstdlib> 
#include <ctime> 
#include <conio.h>

using namespace std;

const int ROWS = 6; 
const int COLS = 6;

void displayArray(int array[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftArray(int array[][COLS], int rows, int cols, int shifts, string direction) {
    if (direction == "вліво") {
        for (int i = 0; i < rows; ++i) {
            for (int shift = 0; shift < shifts; ++shift) {
                int temp = array[i][0];
                for (int j = 0; j < cols - 1; ++j) {
                    array[i][j] = array[i][j + 1];
                }
                array[i][cols - 1] = temp;
            }
        }
    }
    else if (direction == "вправо") {
        for (int i = 0; i < rows; ++i) {
            for (int shift = 0; shift < shifts; ++shift) {
                int temp = array[i][cols - 1];
                for (int j = cols - 1; j > 0; --j) {
                    array[i][j] = array[i][j - 1];
                }
                array[i][0] = temp;
            }
        }
    }
    else if (direction == "вниз") {
        for (int shift = 0; shift < shifts; ++shift) {
            int temp[COLS];
            for (int j = 0; j < cols; ++j) {
                temp[j] = array[rows - 1][j];
            }
            for (int i = rows - 1; i > 0; --i) {
                for (int j = 0; j < cols; ++j) {
                    array[i][j] = array[i - 1][j];
                }
            }
            for (int j = 0; j < cols; ++j) {
                array[0][j] = temp[j];
            }
        }
    }
    else if (direction == "вверх") {
        for (int shift = 0; shift < shifts; ++shift) {
            int temp[COLS];
            for (int j = 0; j < cols; ++j) {
                temp[j] = array[0][j];
            }
            for (int i = 0; i < rows - 1; ++i) {
                for (int j = 0; j < cols; ++j) {
                    array[i][j] = array[i + 1][j];
                }
            }
            for (int j = 0; j < cols; ++j) {
                array[rows - 1][j] = temp[j];
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(nullptr));

    int array[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = rand() % 10;
        }
    }

    cout << "Початковий масив:" << endl;
    displayArray(array, ROWS, COLS);

    int shifts;
    string direction;
    cout << "\nВведіть кількість зсувів: ";
    cin >> shifts;
    cout << "Введіть напрям зсуву (вліво, вправо, вниз, вверх): ";
    cin >> direction;

    shiftArray(array, ROWS, COLS, shifts, direction);
    cout << "\nЗсунутий масив:" << endl;
    displayArray(array, ROWS, COLS);

    _getch();
    return 0;
}
