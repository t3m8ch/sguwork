#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class ValuePrinter {
public:
  virtual void print(int value) = 0;
};

class OstreamValuePrinter : public ValuePrinter {
private:
  ostream& out;
public:
  OstreamValuePrinter(ostream& out) : out(out) {}

  void print(int value) {
    out << value << ' ';
  }
};

class Command {
public:
  virtual void execute(vector<stack<int>>& stacks) = 0;
};

class PushCommand : public Command {
private:
  int stack_id;
  int value;
  ValuePrinter& printer;

public:
  PushCommand(
    int stack_id, 
    int value, 
    ValuePrinter& printer
  ) : stack_id(stack_id), 
      value(value), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) {
    stacks[stack_id - 1].push(value);
  }

  int get_stack_id() const {
    return stack_id;
  }

  int get_value() const {
    return value;
  }
};

class PopCommand : public Command {
private:
  int stack_id;
  ValuePrinter& printer;

public:
  PopCommand(
    int stack_id, 
    ValuePrinter& printer
  ) : stack_id(stack_id), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) {
    printer.print(stacks[stack_id - 1].top());
    stacks[stack_id - 1].pop();
  }

  int get_stack_id() const {
    return stack_id;
  }
};

class TopCommand : public Command {
private:
  int stack_id;
  ValuePrinter& printer;

public:
  TopCommand(
    int stack_id, 
    ValuePrinter& printer
  ) : stack_id(stack_id), 
      printer(printer) {}

  void execute(vector<stack<int>>& stacks) {
    printer.print(stacks[stack_id - 1].top());
  }

  int get_stack_id() const {
    return stack_id;
  }
};

class CanNotParseCommand : public exception {
public:
  string what() {
    return "Can't parse command";
  }
};

class CommandParser {
private:
  ValuePrinter& printer;

  PushCommand* parse_push(const string& cmd_str) {
    string stack_id_str = "";
    string value_str = "";

    int j = 5;
    while (cmd_str[j] != ',') {
      stack_id_str.push_back(cmd_str[j]);
      j++;
    }

    for (int i = j + 1; cmd_str[i] != ')'; i++) {
      value_str.push_back(cmd_str[i]);
    }

    return new PushCommand(stoi(stack_id_str), stoi(value_str), printer);
  }

  TopCommand* parse_top(const string& cmd_str) {
    string stack_id_str = "";
    for (int i = 4; cmd_str[i] != ')'; i++) {
      stack_id_str.push_back(cmd_str[i]);
    }

    return new TopCommand(stoi(stack_id_str), printer);
  }

  PopCommand* parse_pop(const string& cmd_str) {
    string stack_id_str = "";
    for (int i = 4; cmd_str[i] != ')'; i++) {
      stack_id_str.push_back(cmd_str[i]);
    }

    return new PopCommand(stoi(stack_id_str), printer);
  }

public:
  CommandParser(ValuePrinter& printer) : printer(printer) {}

  Command* parse_command(const string& cmd_str) {
    if (cmd_str.substr(0, 4) == "PUSH") {
      return parse_push(cmd_str);
    }

    if (cmd_str.substr(0, 3) == "TOP") {
      return parse_top(cmd_str);
    }

    if (cmd_str.substr(0, 3) == "POP") {
      return parse_pop(cmd_str);
    }

    throw CanNotParseCommand();
  }
};

int main() {
  auto printer = OstreamValuePrinter(cout);
  auto parser = CommandParser(printer);
  
  int stacks_count, operations_count;
  cin >> stacks_count >> operations_count;
  cin.get();

  string line;
  vector<stack<int>> stacks(stacks_count);

  for (int i = 0; i < operations_count; i++) {
    getline(cin, line);
    auto command = parser.parse_command(line);
    command->execute(stacks);
  }
}
