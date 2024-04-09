#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class QueueException {
private:
  string str;

public:
  QueueException(string message) : str(message) {}
  string what() {
    return str;
  }
};

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
      throw QueueException("Queue is empty");
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
  char l;

  ifstream in("input.txt");
  in >> l;

  string word;
  Queue<string> q1;
  while (in >> word) {
    q1.put(word);
  }

  in.close();

  Queue<string> q2;
  while (!q1.isEmpty()) {
    string w = q1.pop();
    if (w[0] == l) {
      q2.put(w);
    }
  }

  ofstream out("output_queue.txt");

  out << q2.getCount() << endl;
  while (!q2.isEmpty()) {
    out << q2.pop() << ' ';
  }
  out << endl;
  out.close();

  return 0;
}
