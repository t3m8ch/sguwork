#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Enemy {
protected:
  string name;
  int attackPower;

  Enemy(const string& name, int attackPower) : name(name), attackPower(attackPower) {}
  Enemy() : name("UNKNOWN"), attackPower(0) {}
public:
  virtual void attack() = 0;
  virtual void printInfo() = 0;
};

class Lancer : public Enemy {
public:
  Lancer() : Enemy() {}
  Lancer(const string& name, int attackPower) : Enemy(name, attackPower) {}

  void attack() {
    cout << "Рыцарь атакаует" << endl;
  }

  void printInfo() {
    cout << "Рыцарь " << name << " с силой атаки " << attackPower << endl;
  }
};

class Dragon : public Enemy {
public:
  Dragon() : Enemy() {}
  Dragon(const string& name, int attackPower) : Enemy(name, attackPower) {}

  void attack() {
    cout << "Дракон атакует" << endl;
  }

  void printInfo() {
    cout << "Дракон " << name << " с силой атаки " << attackPower << endl;
  }
};

int main() {
  vector<Enemy*> enemies = {
    new Lancer("Сэр Артём", 9000000),
    new Dragon("Беззубик", 20000000),
    new Lancer("Сэр Владик", 3000000),
    new Dragon("Мария", 666666),
    new Lancer("Сэр Тимур", 0),
    new Lancer(),
    new Dragon(),
  };

  for (auto e : enemies) {
    e->printInfo();
    e->attack();
    cout << endl;
  }
}

