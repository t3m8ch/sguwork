#include <fstream>
#include <queue>

using namespace std;

int main() {
  ifstream in("input.txt");

  queue<int> q;
  int n;

  int x, y;
  in >> x >> y;

  while (in >> n) {
    q.push(n);
  }
  in.close();

  ofstream out("output_queue.txt");
  while (!q.empty()) {
    out << q.front() << ' ';
    if (q.front() == x) {
      out << y << ' ';
    }
    q.pop();
  }
  out << endl;

  out.close();

  return 0;
}
