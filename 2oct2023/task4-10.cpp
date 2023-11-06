#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int b1 = 2;
    int b2 = 4;

    for (int i = 3; i <= n; ++i) {
        int bn = 6 * b2 - b1;
        cout << "b" << i << " = " << bn << endl;

        b1 = b2; 
        b2 = bn;
    }

    return 0;
}

