#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream in("input.txt");

    queue<int> q;
    int x, n;
    in >> x;

    while (in >> n) {
        q.push(n);
    }

    in.close();

    ofstream out("output.txt");
    while (!q.empty()) {
        int front = q.front();
        if (front != x) {
            out << front << ' ';
        }
        q.pop();
    }
    out << endl;

    out.close();

    return 0;
}
