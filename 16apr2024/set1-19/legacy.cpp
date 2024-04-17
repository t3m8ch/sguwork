#include <set>
#include <fstream>

using namespace std;

set<int> digitize(int n) {
  n = abs(n);
  set<int> digits;
  while (n != 0) {
    digits.insert(n % 10);
    n /= 10;
  }
  return digits;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  int numbers[3];

  while (in >> numbers[0] >> numbers[1] >> numbers[2]) {
    set<int> digitsOfNumbers[3];
    set<int> allDigits;

    for (int i = 0; i < 3; i++) {
      digitsOfNumbers[i] = digitize(numbers[i]);
      allDigits.insert(digitsOfNumbers[i].begin(), digitsOfNumbers[i].end());
    }

    for (int d : allDigits) {
      int c = 0;

      for (int i = 0; i < 3; i++) {
        if (digitsOfNumbers[i].count(d) == 1) {
          c++;
        }
      }

      if (c == 2) {
        out << d << ' ';        
      }
    }
    out << endl;
  }

  in.close();
  out.close();
}
