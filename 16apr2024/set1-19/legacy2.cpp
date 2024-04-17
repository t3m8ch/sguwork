#include <set>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void rightTrim(string& s) {
  s.erase(
    find_if(s.rbegin(), s.rend(), [](unsigned char ch) { 
      return !isspace(ch); 
    }).base(),
    s.end()
  );
}

vector<int> getNumbers(string& line) {
  rightTrim(line);

  vector<int> numbers;
  string word;
  for (char lt : line) {
    if (lt == ' ') {
      numbers.push_back(stoi(word));
      word = "";
    } else {
      word.push_back(lt);
    }
  }

  numbers.push_back(stoi(word));
  return numbers;
}

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

  string line;
  getline(in, line);

  vector<int> numbers = getNumbers(line);
  for (int i = 0; i < numbers.size() - 2; i++) {
    set<int> digitsOfNumbers[3];
    set<int> allDigits;

    for (int j = 0; j < 3; j++) {
      digitsOfNumbers[j] = digitize(numbers[i + j]);
      allDigits.insert(digitsOfNumbers[j].begin(), digitsOfNumbers[j].end());
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
}
