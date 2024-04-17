#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int el = *max_element(numbers.begin(), numbers.end());
    auto m = remove(numbers.begin(), numbers.end(), el);

    for (auto i = numbers.begin(); i < m; ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}