#include <fstream>
#include <string>

using namespace std;

class Stack {
private:
  struct Element {
    string inf;
    Element* next;

    Element(string inf, Element* next) : inf(inf), next(next) {}
  };

  Element* head;

public:
  Stack() : head(0) {}

  bool isEmpty() {
    return head == 0;
  }
  
  string pop() {
    if (isEmpty()) {
      return "";
    }

    Element* r = head;
    string i = r->inf;
    head = r->next;

    delete r;
    return i;
  }

  void push(string data) {
    head = new Element(data, head);
  }

  string getTop() {
    return isEmpty() ? "" : head->inf;
  }
};

int main() {
  char l;

  ifstream in("input.txt");
  in >> l;

  string word;
  Stack stack;
  while (in >> word) {
    if (word[0] == l) {
      stack.push(word);
    }
  }

  in.close();

  ofstream out("output_stack.txt");
  while (!stack.isEmpty()) {
    out << stack.pop() << ' ';
  }
  out << endl;

  out.close();

  return 0;
}
