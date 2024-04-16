#include <map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isWordAndPolyndrome(const string& word) {
  for (size_t i = 0; i < word.length() / 2 + 1; i++) {
    if (
      isdigit(word[i]) || 
      isdigit(word[word.length() - i - 1]) || 
      word[i] != word[word.length() - i - 1]
    ) {
      return false;
    }
  }

  return true;
}

int main() {
  map<string, vector<int>> polyndromeIndexes;

  string word;
  ifstream in("input.txt");
  int i = 0;
  while (in >> word) {
    if (isWordAndPolyndrome(word)) {
      polyndromeIndexes[word].push_back(i);
    }
    i += word.length() + 1;
  }
  in.close();

  ofstream out("output.txt");
  for (const auto& [word, indexes] : polyndromeIndexes) {
    out << word << ' ';
    for (auto i : indexes) {
      out << i << ' ';
    }
    out << endl;
  }
  out.close();

  return 0;
}
