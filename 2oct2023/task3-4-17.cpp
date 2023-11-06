#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << "\t";
        }
        cout << endl;
        for (int j = 1; j <= i; ++j) {
            cout << i + 5 << "\t";
        }
        cout << endl;
    }

    return 0;
}

