#include <iostream>

using namespace std;

int decimal_to_bin(int num) {
  if (num == 0 || num == 1) {
    return num;
  }

  return (num % 2) + 10 * decimal_to_bin(num / 2);
}

int main() {
  int n;
  cin >> n;
  int binary = decimal_to_bin(n);
  cout << binary << endl;

  return 0;
}