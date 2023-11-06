#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double s = 0, a = 0.125, e;
    int i = 1;

    cin >> e;

    while (a >= e) {
        s += a;
        ++i;
        a = 1.0 / pow(i + 1, 3);
    }

    cout << s << endl;

    return 0;
}

