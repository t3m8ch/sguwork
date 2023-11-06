#include <iostream>

using namespace std;

int main() {
    cout << "Введите кол-во элементов: ";
    int n;
    cin >> n;

    int a[100];

    cout << "Введите числа: ";

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int s = 0;

    for (int i = 0; i < n; ++i) {
        s += a[i];
    }

    double avg = double(s) / n;

    cout << "Среднее арифметического введённых чисел: " << avg << endl;

    return 0;
}
