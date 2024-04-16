#include <set>
#include <string>
#include <fstream>

using namespace std;

int main() {
  string word;
  set<char> letters;
  set<char> lastLineLetters;

  ifstream in("input.txt");
  while (getline(in, word)) {
    lastLineLetters.clear();
    for (char l : word) {
      if (!isalpha(l)) {
        continue;
      }

      if (letters.count(l) == 0) {
        lastLineLetters.insert(l);
      }
      letters.insert(l);
    }
  }
  in.close();

  ofstream out("output.txt");
  for (char l : lastLineLetters) {
    out << l << ' ';
  }
  out << endl;
  out.close();

  return 0;
}
