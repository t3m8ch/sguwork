#include <iostream>

using namespace std;

int main() {
  int el;
  cin >> el;
  
  int n;
  cin >> n;

  int *arr = new int[2 * n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int shift = 0;
  for (int i = 1; i < (n + shift); ++i) {
    if (arr[i] % (i - shift) == 0) {
      for (int j = n + shift; j > i; --j) {
        arr[j] = arr[j - 1];
      }
      arr[i + 1] = el;
      ++i;
      ++shift;
    }
  }

  for (int i = 0; i < (n + shift); ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;

  return 0;
}

