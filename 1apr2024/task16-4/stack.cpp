#include <fstream>
#include <string>

using namespace std;

class StackException {
private:
  string str;

public:
  StackException(string message) : str(message) {}
  string what() {
    return str;
  }
};

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
      throw StackException("Stack is empty");
    }

    Element* r = head;
    Item i = r->inf;
    head = r->next;

    delete r;
    count--;
    return i;
  }

  void push(string data) {
    head = new Element(data, head);
    count++;
  }

  Item getTop() {
    if (isEmpty()) {
      throw StackException("Stack is empty");
    }

    return isEmpty() ? "" : head->inf;
  }

  unsigned getCount() {
    return count;
  }
};

int main() {
  char l;

  ifstream in("input.txt");
  in >> l;

  string word;
  Stack<string> stack1;
  while (in >> word) {
    stack1.push(word);
  }

  in.close();

  Stack<string> stack2;
  while (!stack1.isEmpty()) {
    string w = stack1.pop();
    if (w[0] == l) {
      stack2.push(w);
    }
  }

  ofstream out("output_stack.txt");
  out << stack2.getCount() << endl;
  while (!stack2.isEmpty()) {
    out << stack2.pop() << ' ';
  }
  out << endl;

  out.close();

  return 0;
}
