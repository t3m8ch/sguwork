#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

int main() {
  ifstream in("input.txt");

  stack<int> st;
  int n;

  int x, y;
  in >> x >> y;

  while (in >> n) {
    st.push(n);
  }

  stack<int> st2;
  while (!st.empty()) {
    if (st.top() == x) {
      st2.push(y);
    }
    st2.push(st.top());
    st.pop();
  }

  in.close();

  ofstream out("output_stack.txt");
  while (!st2.empty()) {
    out << st2.top() << ' ';
    st2.pop();
  }
  out << endl;

  out.close();

  return 0;
}
