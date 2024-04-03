#include <fstream>
#include <stack>

using namespace std;

int main() {
  ifstream in("input.txt");

  stack<int> st;
  int n;

  int x, y;
  in >> x >> y;

  while (in >> n) {
    st.push(n);
    if (n == x) {
      st.push(y);
    }
  }

  in.close();

  ofstream out("output_stack.txt");
  while (!st.empty()) {
    out << st.top() << ' ';
    st.pop();
  }
  out << endl;

  out.close();

  return 0;
}
