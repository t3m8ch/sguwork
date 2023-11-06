#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    double result = 0.5 * a * b;
    cout << fixed << setprecision(3) << result << endl;

    return 0;
}

