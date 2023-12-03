#include <iostream>
#include <cmath>

using namespace std;

int dividers_sum(int n) {
  int s = 0;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      s += i + n / i;
    }
  }
  return s;
}

int main() {
  int n;
  cin >> n;

  int prev = n;

  int div_sum_n = dividers_sum(n);

  do {
    --prev;
  } while (div_sum_n != dividers_sum(prev));

  cout << prev << endl;

  return 0;
}

