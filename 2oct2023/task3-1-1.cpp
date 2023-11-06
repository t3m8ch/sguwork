#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    double a = pow(x, 2) + pow(y, 2);

    if ((a < 9) && (y > 0)) {
        cout << "Да" << endl;
    } else if (((a < 9) && (y == 0)) || ((a == 9) && (y >= 0))) {
        // Переместить на границе в else
        cout << "На границе" << endl;
    } else {
        cout << "Нет" << endl;
    }

    return 0;
}

