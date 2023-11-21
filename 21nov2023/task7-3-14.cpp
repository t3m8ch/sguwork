#include <iostream>
#include <cctype>

using namespace std;

int main() {
  char s[101];
  cin.getline(s, 100);

  if (s[0] != ' ') {
    s[0] = toupper(s[0]);
  }

  for (int i = 1; s[i] != '\0'; ++i) {
    if (s[i - 1] == ' ') {
      s[i] = toupper(s[i]);
    }
  }

  cout << s << endl;

  return 0;
}

