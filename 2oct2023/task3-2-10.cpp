#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;

    switch ((year - 8) % 12) {
        case 0:
            cout << "Дракон" << endl;
            break;
        case 1:
            cout << "Змея" << endl;
            break;
        case 2:
            cout << "Лошадь" << endl;
            break;
        case 3:
            cout << "Овца" << endl;
            break;
        case 4:
            cout << "Обезьяна" << endl;
            break;
        case 5:
            cout << "Петух" << endl;
            break;
        case 6:
            cout << "Собака" << endl;
            break;
        case 7:
            cout << "Свинья" << endl;
            break;
        case 8:
            cout << "Крыса" << endl;
            break;
        case 9:
            cout << "Бык" << endl;
            break;
        case 10:
            cout << "Тигр" << endl;
            break;
        case 11:
            cout << "Кролик" << endl;
            break;
    }

    return 0;
}

