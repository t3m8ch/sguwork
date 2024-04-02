#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit {
protected:
  string name;
  int health;
  int damage;

public:
  Unit() : name("Pudge"), health(1000), damage(100) {}
  Unit(string name, int health, int damage)
      : name(name), health(health), damage(damage) {}

  string getName() { return name; }
  void setName(string name) { this->name = name; }

  int getHealth() { return health; }
  void setHealth(int health) { this->health = health; }

  int getDamage() { return damage; }
  void setDamage(int damage) { this->damage = damage; }

  void print(ostream &out) {
    out << "Unit: " << name << endl
        << "  health: " << health << endl
        << "  damage: " << damage << endl;
  }
};

class Lancer : public Unit {
private:
  int armor;

public:
  Lancer() : Unit() {}
  Lancer(string name, int health, int damage, int armor)
      : Unit(name, health, damage), armor(armor) {}

  int getArmor() { return armor; }
  void setArmor(int armor) { this->armor = armor; }

  void print(ostream &out) {
    out << "Lancer: " << name << endl
        << "  health: " << health << endl
        << "  damage: " << damage << endl
        << "  armor: " << armor << endl;
  }
};

class Mage : public Unit {
private:
  int mana;

public:
  Mage() : Unit() {}
  Mage(string name, int length, int damage, int mana)
      : Unit(name, length, damage), mana(mana) {}
  
  int getMana() { return mana; }
  void setMana(int mana) { this->mana = mana; }

  void print(ostream &out) {
    out << "Lancer: " << name << endl
        << "  health: " << health << endl
        << "  damage: " << damage << endl
        << "  mana: " << mana << endl;
  }

  bool operator==(Mage mage) {
    return mana == mage.mana;
  }

  bool operator!=(Mage mage) {
    return mana != mage.mana;
  }

  bool operator>(Mage mage) {
    return mana > mage.mana;
  }

  bool operator<(Mage mage) {
    return mana < mage.mana;
  }
};

int main() {

  return 0;
}
