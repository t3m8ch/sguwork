#include <fstream>

using namespace std;

template <class Item> class Stack {
private:
  struct Element {
    Item inf;
    Element* next;
    Element(Item inf, Element* next) : inf(inf), next(next) {}
  };

  Element* head;
  unsigned count = 0;

public:
  Stack() : head(0) {}

  bool isEmpty() {
    return head == 0;
  }
  
  Item pop() {
    if (isEmpty()) {
      throw "Stack is empty";
    }

    Element* r = head;
    Item i = r->inf;
    head = r->next;

    delete r;
    count--;
    return i;
  }

  void push(Item data) {
    head = new Element(data, head);
    count++;
  }

  Item getTop() {
    if (isEmpty()) {
      throw "Stack is empty";
    }

    return head->inf;
  }

  unsigned getCount() {
    return count;
  }
};

int main() {
  Stack<int> s1;
  ifstream in("input.txt");

  int n;
  while (in >> n) {
    s1.push(n);
  }
  in.close();

  Stack<int> s2;
  while (!s1.isEmpty()) {
    int top = s1.pop();
    if (top % 2 == 0) {
      s2.push(top);
    }
  }

  ofstream out("output.txt");

  int s = 0;
  int count = 0;
  while (!s2.isEmpty()) {
    int top = s2.pop();
    out << top << ' ';
    s += top;
    count++;
  }

  out << endl;
  out << s / double(count) << endl;
  out.close();

  return 0;
}