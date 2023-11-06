#include <iostream>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    if (( (x >= -2.5) && (x <= -1) ) || (x >= 2.5)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
