#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    if ((M % N) == 0) {
        cout << M / N << endl;
    } else {
        cout << "M на N нацело не делится" << endl;
    }
    
    return 0;
}

