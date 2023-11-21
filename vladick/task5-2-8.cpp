#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double s = 0;

  int k;
  double x;

  cout << "k = ";
  cin >> k;

  cout << "x = ";
  cin >> x;

  double a = -1;

  for (int i = 1; i <= k; ++i) {
    a *= (-1 * x) / ((2*i - 1) * 2*i); 
    s += a;
  }

  cout << s << endl;

  return 0;
}

