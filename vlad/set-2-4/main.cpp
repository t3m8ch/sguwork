#include <set>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
  string word;
  set<char> letters;
  set<char> firstLineLetters;

  ifstream in("input.txt");

  getline(in, word);
  for (char lt : word) {
    if (!isalpha(lt)) {
      continue;
    }

    firstLineLetters.insert(lt);
  }

  while (getline(in, word)) {
    for (char lt : word) {
      if (!isalpha(lt)) {
        continue;
      }

      letters.insert(lt);
    }
  }
  in.close();

  ofstream out("output.txt");
  set<char> result;

  set_difference(
    firstLineLetters.begin(), firstLineLetters.end(), 
    letters.begin(), letters.end(), 
    inserter(result, result.begin())
  );

  for (char letter : result) {
    out << letter << ' ';
  }
  out << endl;
  out.close();

  return 0;
}
