#include <iostream>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    
    if ((x <= -2) && (y >= 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

