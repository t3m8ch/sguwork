#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % 2 == 0 && n != 2) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    numbers.push_back(num);
  }

  replace_if(numbers.begin(), numbers.end(), isPrime, x);

  for (int i = 0; i < n; ++i) {
    cout << numbers[i] << ' ';
  }
  cout << endl;

  return 0;
}
