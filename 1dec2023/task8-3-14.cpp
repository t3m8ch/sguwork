#include <iostream>

using namespace std;

void f(int a, int b) {
  char l = 'A' + (a - b);
  for (int i = 0; i < (a - b); i++) {
    cout << ' ';
  }
  for (int i = 0; i < 80 - (a - b) * 2; i++) {
    cout << l;
  }
  cout << endl;
  if (a < 25) {
    f(a + 1, b);
  } else if (b < 25) {
    f(a, b + 1);
  }
}

int main() {
  f(0, 0);
  return 0;
}
