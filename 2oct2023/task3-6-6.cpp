#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    double a = pow(x, 2) + 2 * x + + 1;
    if (a < 2) {
        return pow(x, 2);
    }

    if ((a >= 2) && (a < 3)) {
        return 1.0 / (pow(x, 2) -1);
    }

    return 0;
}

int main() {
    double a, b, h;
    cin >> a >> b >> h;

    for (double i = a; i <= b; i += h) {
        cout << "f(" << i << ") = " << f(i) << endl;
    }

    return 0;
}

