#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  double* numbers = new double[n];

  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  bool flag = false;
  double s = 0;
  for (int i = 0; i < n; ++i) {
    if (numbers[i] < 0 && !flag) {
      flag = true;
      continue;
    }

    if (numbers[i] < 0 && flag) {
      flag = false;
      break;
    }

    if (flag) {
      s += numbers[i];
    }
  }

  if (flag) {
    cout << 0 << endl;
    return 0;
  }

  cout << fixed << setprecision(3) << s << endl;

  return 0;
}

