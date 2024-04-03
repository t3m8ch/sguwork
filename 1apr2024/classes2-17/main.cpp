#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  virtual void printInfo(ostream &out) const {
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

  void printInfo(ostream &out) const {
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
  Mage() : Unit(), mana(50) {}
  Mage(string name, int health, int damage, int mana)
      : Unit(name, health, damage), mana(mana) {}
  
  int getMana() { return mana; }
  void setMana(int mana) { this->mana = mana; }

  void printInfo(ostream &out) const {
    out << "Mage: " << name << endl
        << "  health: " << health << endl
        << "  damage: " << damage << endl
        << "  mana: " << mana << endl;
  }

  bool operator==(const Mage& mage) {
    return mana == mage.mana;
  }

  bool operator!=(const Mage& mage) {
    return mana != mage.mana;
  }

  bool operator>(const Mage& mage) {
    return mana > mage.mana;
  }

  bool operator<(const Mage& mage) {
    return mana < mage.mana;
  }

  bool canWin(const Mage& mage) {
    return *this > mage;
  }
};

class TopOfMages {
private:
  vector<Mage*> mages;

  void sortMages() {
    sort(mages.begin(), mages.end(), [](Mage* mage1, Mage* mage2) { 
      return *mage1 > *mage2; 
    });
  }
public:
  TopOfMages() {}
  
  TopOfMages(vector<Mage*> mages) {
    this->mages = mages;
    sortMages();
  }

  void add(Mage* mage) {
    mages.push_back(mage);
    sortMages();
  }

  const vector<Mage*>& get() {
    return mages;
  }

  void print(ostream& out) {
    out << "TOP OF MAGES:" << endl;
    for (Mage* mage : mages) {
      mage->printInfo(out);
    }
  }
};


int main() {
  vector<Unit*> units = {
    new Unit("Petr", 1000, 100),
    new Unit("Vasya", 500, 250),
    new Lancer("Argon300", 2000, 35, 500),
    new Mage("damager2005", 450, 300, 100),
  };

  for (Unit* unit : units) {
    unit->printInfo(cout);
  }

  cout << endl;

  TopOfMages* topOfMages = new TopOfMages({
    new Mage(),
    new Mage("Maga2.1", 100, 100, 350),
    new Mage("Maga2.2", 150, 150, 350),
    new Mage("Maga3", 100, 100, 10),
    new Mage("Maga4", 100, 100, 75),
  });

  topOfMages->print(cout);

  cout << endl;

  Mage* mage1 = topOfMages->get()[0];
  Mage* mage2 = topOfMages->get()[1];
  Mage* mage3 = topOfMages->get()[3];

  cout << (mage1->canWin(*mage2) ? "mage1 can win mage2" : "mage1 can't win mage2") << endl;
  cout << (mage1->canWin(*mage3) ? "mage1 can win mage3" : "mage1 can't win mage3") << endl;

  cout << endl;

  topOfMages->add(new Mage("Imba", 10000, 10000, 10000));
  topOfMages->print(cout);

  return 0;
}
