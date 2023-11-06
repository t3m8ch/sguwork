#include <iostream>

using namespace std;

int main() {
    cout << "for:" << endl;
    for (int i = 101; i < 1000; ++i) {
        if (i % 10 == i / 100) {
            cout << i << " ";
        }
    }

    cout << endl << endl;

    cout << "while:" << endl;
    int j = 101;
    while (j < 1000) {
        if (j % 10 == j / 100) {
            cout << j << " ";
        }
        ++j;
    }

    cout << endl << endl;;

    cout << "do while:" << endl;   
    int k = 101;
    do {
        if (k % 10 == k / 100) {
            cout << k << " ";
        }
        ++k;
    } while (k < 1000);

    cout << endl;

    return 0;
}

