#include <iostream>

using namespace std;

int main() {
    cout << "Введите кол-во элементов: ";
    int n;
    cin >> n;

    double *arr = new double[n];

    cout << "Введите числа: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int nmax = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] >= arr[nmax]) {
            nmax = i;
        }
    }

    cout << "Номер максимального элемента: " << nmax << endl;

    return 0;
}

