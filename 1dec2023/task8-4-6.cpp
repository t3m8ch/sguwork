#include <iostream>

using namespace std;

float F(float x) {
  float a = x*x + 2*x + 1;
  if (a < 2) {
    return x*x;
  } else if (a < 3) {
    return 1.0 / (x*x - 1);
  } else {
    return 0;
  }
}

void F(float x, float &y) {
  float a = x*x + 2*x + 1;
  if (a < 2) {
    y = x*x;
  } else if (a < 3) {
    y = 1.0 / (x*x - 1);
  } else {
    y = 0;
  }
}

int main() {
  // x = 0 => f(x) = 0
  // x = 0.5 => f(x) = -1.333...
  // x = 1 => f(x) = 0
  float x;
  cin >> x;

  float y;
  F(x, y);

  cout << F(x) << " " << y << endl;
  return 0;
}
