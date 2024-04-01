#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    numbers.push_back(num);
  }

  numbers.erase(min_element(numbers.rbegin(), numbers.rend()).base() - 1); 

  for (int i = 0; i < numbers.size(); ++i) {
    cout << numbers[i] << ' ';
  }
  cout << endl;
}