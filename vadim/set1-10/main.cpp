#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<int> digits(int n) {
    set<int> result;

    while (n != 0) {
        result.insert(n % 10);
        n /= 10;
    }

    return result;
}

int main() {
    ifstream in("input.txt");
    vector<int> numbers;
    int n;

    while (in >> n) {
        numbers.push_back(n);
    }

    in.close();

    set<int> first = digits(numbers[0]);
    set<int> last = digits(numbers[numbers.size() - 1]);

    set<int> result;
    set_intersection(
        first.begin(), first.end(), 
        last.begin(), last.end(), 
        inserter(result, result.end())
    );

    for (int i = 1; i < numbers.size() - 1; i++) {
        set<int> curr = digits(numbers[i]);
        set_difference(
            result.begin(), result.end(), 
            curr.begin(), curr.end(), 
            inserter(result, result.end())
        );
    }

    ofstream out("output.txt");
    for (int i : result) {
        out << i << ' ';
    }
    out.close();

    return 0;
}
