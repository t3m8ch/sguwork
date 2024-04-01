#include <iterator>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>

using namespace std;

vector<double>::iterator lastPositiveNumber(vector<double>& numbers) {
  vector<double>::iterator iter = numbers.begin();

  while (iter != numbers.end()) {
    if (*iter < 0) {
      break;
    }
    iter++;
  }

  if (numbers.begin() == iter) {
    return numbers.end();
  }

  return iter - 1;
}

void fillVector(vector<double>& numbers, istream& input) {
  int n;
  input >> n;
  for (int i = 0; i < n; ++i) {
    double number;
    input >> number;
    numbers.push_back(number);
  }
}

int main() {
  vector<double> numbers;
  fillVector(numbers, cin);

  vector<double>::iterator lastposnum = lastPositiveNumber(numbers);

  if (lastposnum == numbers.end() || lastposnum == numbers.begin()) {
    cout << 0 << endl;
    return 0;
  }

  cout << accumulate(numbers.begin(), lastposnum, 0.0) << endl;
  return 0;
}
