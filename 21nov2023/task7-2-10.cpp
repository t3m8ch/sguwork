#include <iostream>

using namespace std;

int main() {
  char s[101];
  cin.getline(s, 100);

  for (int i = 0; s[i] != '\0'; ++i) {
    for (int j = i + 1; s[j] != '\0'; ++j) {
      bool flag = false;
      if (s[i] == s[j]) {
        cout << s[i] << endl;
        flag = true;
        break;
      }
      if (flag) {
        break;
      }
    }
  }

  return 0;
}

