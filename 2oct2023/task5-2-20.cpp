#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k;
    double x;
    cin >> k >> x;

    double p = 1;

    double b_curr = 1;
    double z_curr = -1;

    for (int n = 0; n <= k; ++n) {
        p *= (1 + (z_curr * b_curr) / ( (n + 2) * (n + 1) ));
        b_curr *= pow(x, 2);
        z_curr *= -1;
    }

    cout << p << endl;

    return 0;
}

