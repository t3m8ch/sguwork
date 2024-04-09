#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class NotDefinedInX {
private:
  double x;
public:
  NotDefinedInX(double x) : x(x) {}
  double getX() {
    return x;
  }
};

double f(double x) {
  if (x < pow(0.5, 1 / 5.0)) {
    throw NotDefinedInX(x);
  }
  return log(3 * x) * sqrt(2 * pow(x, 5) - 1);
}

int main() {
  double a, b, h;  
  cin >> a >> b >> h;

  cout << "x\tf(x)" << endl;
  for (double x = a; x <= b; x += h) {
    try {
      cout << x << '\t' << f(x) << endl;
    } catch (NotDefinedInX) {
      cout << "undef" << endl;
    }
  }

  return 0;
}
