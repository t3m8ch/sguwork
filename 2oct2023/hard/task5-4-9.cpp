#include <iostream>

using namespace std;

double f(double x, double e, int &n) {
  double s = 0, a = 1, b = 1;
  n = 0;

  while (a >= e) {
    s += a;
    ++n;
    b = (b + 2);
    a *= (x / b);
  }

  return s;
}

int main() {
  double e;
  cout << "Введите точность: ";
  cin >> e;

  int i = 1;

  cout << "i\tx\tf(x)\tn" << endl;

  for (double x = 0.05; x <= 0.95; x += 0.1) {
    int n;
    double y = f(x, e, n);
    cout << i << "\t" << x << "\t" << y << "\t" << n << endl;
    ++i;
  }
}
