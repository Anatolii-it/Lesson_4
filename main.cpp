#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int n;
    cout << "������ ������� �������� ������: ";
    cin >> n;

    vector<int> array(n);

    cout << "������ ����� �����: ";
    cin >> array[0];

    for (int i = 1; i < n; ++i) {
        array[i] = array[i - 1] * 2;
    }

    cout << "������� �����: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    

    _getch();
    return 0;
}