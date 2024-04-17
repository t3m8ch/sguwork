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
    for (char lt : word) {
      if (!isalpha(lt)) {
        continue;
      }

      if (letters.count(lt) == 0) {
        lastLineLetters.insert(lt);
      }
      letters.insert(lt);
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
