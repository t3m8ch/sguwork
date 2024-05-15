#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream in("input.txt");

    stack<int> s;
    int x, n;
    in >> x;

    while (in >> n) {
        s.push(n);
    }

    in.close();

    stack<int> s2;
    while (!s.empty()) {
        if (s.top() != x) {
            s2.push(s.top());
        }
        s.pop();
    }

    ofstream out("output.txt");
    while (!s2.empty()) {
        out << s2.top() << ' ';
        s2.pop();
    }
    out << endl;

    out.close();

    return 0;
}
