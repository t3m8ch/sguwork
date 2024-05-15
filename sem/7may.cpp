#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // N, N-целых чисе, y. Создать вектор из чисел и потом заменить двухзначные числа на y. 
    // Вывести вектор по итераторам
    unsigned n;
    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int y;
    cin >> y;

    replace_if(numbers.begin(), numbers.end(), [](const int value) {
        return abs(value) >= 10 && abs(value) <= 99;
    }, y);

    for (int n : numbers) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}
