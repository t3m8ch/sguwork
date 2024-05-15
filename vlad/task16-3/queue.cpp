#include <fstream>

using namespace std;

template <class Item> class Queue {
private:
  struct Element {
    Item inf;
    Element* next;
    Element(Item x) : inf(x), next(0) {}
  };
  Element *head, *tail;
  unsigned count = 0;
public:
  Queue() : head(0), tail(0) {}
  bool isEmpty() {
    return head == 0;
  }

  Item pop() {
    if (isEmpty()) {
      throw "Queue is empty";
    } else {
      Element* t = head;
      Item i = t->inf;
      head = t->next;

      if (head == NULL) {
        tail = NULL;
      }

      delete t;
      count--;
      return i;
    }
  }

  void put(Item data) {
    Element* t = tail;
    tail = new Element(data);

    if (!head) {
      head = tail;
    } else {
      t->next = tail;
    }

    count++;
  }

  unsigned getCount() {
    return count;
  }
};

int main() {
  Queue<int> q;

  ifstream in("input.txt");
  int n;
  while (in >> n) {
    q.put(n);
  }
  in.close();

  ofstream out("output.txt");
  int s = 0;
  int count = 0;
  while (!q.isEmpty()) {
    int top = q.pop();
    if (top % 2 == 0) {
      out << top << ' ';
      s += top;
      count++;
    }
  }

  out << endl;
  out << s / double(count) << endl;
  out.close();

  return 0;
}
