#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 1 вариант
    double s1 = 0;

    for (int i = 1; i <= n; ++i) {
        s1 += 1 / sin(i);
    }

    cout << s1 << endl;

    return 0;
}

