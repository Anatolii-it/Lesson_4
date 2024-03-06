#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в масиву: ";
    cin >> n;

    int* array = new int[n];

    cout << "¬вед≥ть перший елемент: ";
    cin >> array[0];

    for (int i = 1; i < n; ++i) {
        array[i] = array[i - 1] + 1;
    }

    cout << "ќтриманий масив: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    _getch();
    return 0;
}
