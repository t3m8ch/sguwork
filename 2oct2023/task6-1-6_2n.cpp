#include <iostream>

using namespace std;

int main() {
    cout << "Введите кол-во строк и столбцов: ";
    int rows, cols;
    cin >> rows >> cols;

    int arr[5][5];

    for (int i = 0; i < rows; ++i) {
        cout << "Введите " << cols << " чисел для строки " << i << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }

    int s = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            s += arr[i][j];
        }
    }

    double avg = double(s) / (rows * cols);

    cout << "Среднее арифмитическое всех чисел: " << avg << endl;

    return 0;
}

