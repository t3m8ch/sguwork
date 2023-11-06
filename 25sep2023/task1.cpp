#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    double result = (1 + sin(pow(x + 1, 0.5))) / cos(12 * y - 4);
    cout << fixed << setprecision(2) << result << endl;

    return 0;
}

