#include <fstream>
#include <list>

using namespace std;

int main() {
  ifstream in("input.txt");

  list<int> l;
  int n;

  int x, y;
  in >> x >> y;

  while (in >> n) {
    l.push_back(n);
  }

  in.close();

  for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
    if (*i == x) {
      l.insert(next(i), y);
    }
  }

  ofstream out("output_list.txt");
  for (list<int>::iterator i = l.begin(); i != l.end(); i++) {
    out << *i << ' ';
  }
  out << endl;

  out.close();

  return 0;
}
