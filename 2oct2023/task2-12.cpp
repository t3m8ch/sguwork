#include <iostream>

using namespace std;

void f(int &x) {
    if ((x >= 10) && (x <= 99)) {
        x = (x % 10) * 10 + (x / 10);
    }
}

int main() {
    int x;
    cin >> x;

    f(x);
    cout << x << endl;

    return 0;
}

