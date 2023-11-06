#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return log(x - 1);
}

int main() {
    double a, b, h;
    cin >> a >> b >> h;

    for (double i = a; i <= b; i += h) {
        cout << "f(" << i << ") = ";

        double result = f(i);
        if (i <= 1) {
            cout << "Функция не определена" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}

