#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  getline(cin, str);

  int s = 0;

  for (int i = 1; i < str.size(); i += 5) {
    int digit = str[i] - '0';
    s += digit;
  }

  cout << s << endl;

  return 0;
}

