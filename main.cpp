#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 

using namespace std;
   

    const int ROWS = 6; //два не достатьно наглядно як на мене
    const int COLS = 6;

    void displayArray(int array[][COLS]) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

    void shiftArray(int array[][COLS], int shifts, string direction) {
        if (direction == "вправо") {
            for (int i = 0; i < ROWS; ++i) {
                for (int shift = 0; shift < shifts; ++shift) {
                    int temp = array[i][COLS - 1];
                    for (int j = COLS - 1; j > 0; --j) {
                        array[i][j] = array[i][j - 1];
                    }
                    array[i][0] = temp;
                }
            }
        }
        else if (direction == "вліво") {
            for (int i = 0; i < ROWS; ++i) {
                for (int shift = 0; shift < shifts; ++shift) {
                    int temp = array[i][0];
                    for (int j = 0; j < COLS - 1; ++j) {
                        array[i][j] = array[i][j + 1];
                    }
                    array[i][COLS - 1] = temp;
                }
            }
        }
        else if (direction == "вниз") {
            for (int shift = 0; shift < shifts; ++shift) {
                int temp[COLS];
                for (int j = 0; j < COLS; ++j) {
                    temp[j] = array[ROWS - 1][j];
                }
                for (int i = ROWS - 1; i > 0; --i) {
                    for (int j = 0; j < COLS; ++j) {
                        array[i][j] = array[i - 1][j];
                    }
                }
                for (int j = 0; j < COLS; ++j) {
                    array[0][j] = temp[j];
                }
            }
        }
        else if (direction == "вгору") {
            for (int shift = 0; shift < shifts; ++shift) {
                int temp[COLS];
                for (int j = 0; j < COLS; ++j) {
                    temp[j] = array[0][j];
                }
                for (int i = 0; i < ROWS - 1; ++i) {
                    for (int j = 0; j < COLS; ++j) {
                        array[i][j] = array[i + 1][j];
                    }
                }
                for (int j = 0; j < COLS; ++j) {
                    array[ROWS - 1][j] = temp[j];
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
        displayArray(array);
        int shifts;
        string direction;
        cout << "\nВведіть кількість зрушень: ";
        cin >> shifts;
        cout << "Введіть напрямок зрушення (вправо, вліво, вниз, вгору): ";
        cin >> direction;

        shiftArray(array, shifts, direction);
        cout << "\nЗрушений масив:" << endl;
        displayArray(array);

     

    _getch();
    return 0;
}

