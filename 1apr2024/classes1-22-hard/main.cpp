#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

class Organizer {
private:
  string name;
  string address;
  string phone;

public:
  Organizer(string _name, string _address, string _phone)
      : name(_name), address(_address), phone(_phone) {}

  string getName() { return name; }
  void setName(string _name) { name = _name; }

  string getAddress() { return address; }
  void setAddress(string _address) { address = _address; }

  string getPhone() { return phone; }
  void setPhone(string _phone) { phone = _phone; }
};

class DateTime {
private:
  int year;
  int month;
  int day;
  int hour;
  int minute;

public:
  DateTime(int _year, int _month, int _day, int _hour, int _minute)
      : year(_year), month(_month), day(_day), hour(_hour), minute(_minute) {}
  
  DateTime(string s) {
    setYear(stoi(s.substr(0, 4)));
    setMonth(stoi(s.substr(5, 2)));
    setDay(stoi(s.substr(8, 2)));
    setHour(stoi(s.substr(11, 2)));
    setMinute(stoi(s.substr(14, 2)));
  }

  bool operator==(DateTime dateTime) {
    return year == dateTime.year && month == dateTime.month &&
           day == dateTime.day && hour == dateTime.hour &&
           minute == dateTime.minute;
  }

  bool operator!=(DateTime dateTime) {
    return year != dateTime.year || month != dateTime.month ||
           day != dateTime.day || hour != dateTime.hour ||
           minute != dateTime.minute;
  }

  bool operator>(DateTime dateTime) {
    return year > dateTime.year ||
           (year == dateTime.year && month > dateTime.month) ||
           (year == dateTime.year && month == dateTime.month &&
            day > dateTime.day) ||
           (year == dateTime.year && month == dateTime.month &&
            day == dateTime.day && hour > dateTime.hour) ||
           (year == dateTime.year && month == dateTime.month &&
            day == dateTime.day && hour == dateTime.hour &&
            minute > dateTime.minute);
  }

  bool operator<(DateTime dateTime) {
    return year < dateTime.year ||
           (year == dateTime.year && month < dateTime.month) ||
           (year == dateTime.year && month == dateTime.month &&
            day < dateTime.day) ||
           (year == dateTime.year && month == dateTime.month &&
            day == dateTime.day && hour < dateTime.hour) ||
           (year == dateTime.year && month == dateTime.month &&
            day == dateTime.day && hour == dateTime.hour &&
            minute < dateTime.minute);
  }

  int getYear() { return year; }
  void setYear(int _year) { year = _year; }

  int getMonth() { return month; }
  void setMonth(int _month) { month = _month; }

  int getDay() { return day; }
  void setDay(int _day) { day = _day; }

  int getHour() { return hour; }
  void setHour(int _hour) { hour = _hour; }

  int getMinute() { return minute; }
  void setMinute(int _minute) { minute = _minute; }
};

class Event {
private:
  string name;
  Organizer organizer;
  DateTime dateTime;
  double cost;

  static int objectsCount;

public:
  Event()
      : name("Event"),
        organizer(Organizer("Компания", "ул. Пушкина", "+7 999 999-99-99")),
        dateTime(DateTime(2024, 1, 1, 0, 0)), cost(1000) {
    objectsCount++;
  }

  Event(string _name, Organizer _organizer, DateTime _dateTime, double _cost)
      : name(_name), organizer(_organizer), dateTime(_dateTime), cost(_cost) {
    objectsCount++;
  }

  string getName() const { return name; }
  void setName(string _name) { name = _name; }

  Organizer getOrganizer() const { return organizer; }
  void setOrganizer(Organizer _organizer) { organizer = _organizer; }

  DateTime getDateTime() const { return dateTime; }
  void setDateTime(DateTime _dateTime) { dateTime = _dateTime; }

  double getCost() const { return cost; }
  void setCost(double _cost) { cost = _cost; }

  static int getObjectsCount() { return Event::objectsCount; }

  void printEvent(ostream& out) {
    out << "Event(name=\"" << name << "\", organizer=Organizer(name=\""
        << organizer.getName() << "\", address=\"" << organizer.getAddress()
        << "\", phone=\"" << organizer.getPhone() << "\"), dateTime=\""
        << dateTime.getYear() << "-" << setw(2) << setfill('0')
        << dateTime.getMonth() << "-" << setw(2) << setfill('0')
        << dateTime.getDay() << " " << setw(2) << setfill('0')
        << dateTime.getHour() << ":" << setw(2) << setfill('0')
        << dateTime.getMinute() << "\", cost=" << cost << ")" << endl;
  }

  bool operator==(Event event) {
    return dateTime == event.getDateTime() || name == event.getName();
  }

  bool operator!=(Event event) {
    return dateTime != event.getDateTime() && name != event.getName();
  }

  bool operator>(Event event) {
    return dateTime > event.getDateTime() ||
           (dateTime == event.getDateTime() && name > event.getName());
  }

  bool operator<(Event event) {
    return dateTime < event.getDateTime() ||
           (dateTime == event.getDateTime() && name < event.getName());
  }
};

int Event::objectsCount = 0;

// Компоратор
bool comp(const Event& a, const Event& b) {
    return a.getDateTime() < b.getDateTime() ||
           (a.getDateTime() == b.getDateTime() && a.getName() < b.getName());
}

void leftTrim(string& s) {
  s.erase(
    s.begin(), 
    find_if(s.begin(), s.end(), [](unsigned char ch) { 
      return !isspace(ch); 
    })
  );
}

void rightTrim(string& s) {
  s.erase(
    find_if(s.rbegin(), s.rend(), [](unsigned char ch) { 
      return !isspace(ch); 
    }).base(),
    s.end()
  );
}

void strToLowerCase(string& s) {
  transform(s.begin(), s.end(), s.begin(), [](unsigned char ch) {
    return tolower(ch);
  });
}

class CannotReadEvent {};

class EventReader {
private:
  istream& in;
  bool eventIsRead = false;
  string currentLine;
  map<string, string> fields;

  void preprocessCurrentLine() {
    leftTrim(currentLine);
    rightTrim(currentLine);
    strToLowerCase(currentLine);
  }

  Event createEventFromMap() {
    DateTime dateTime(fields["datetime"]);
    Organizer organizer(
      fields["organizer.name"],
      fields["organizer.address"],
      fields["organizer.phone"]
    );
    return Event(fields["name"], organizer, dateTime, stod(fields["cost"]));
  }

  void parseFieldToMap() {
    string::iterator eq = find(currentLine.begin(), currentLine.end(), '=');
    string key(currentLine.begin(), eq);
    string value(eq + 1, currentLine.end());
    fields[key] = value;
  }
public:
  EventReader(istream& in) : in(in) {}
  Event readEvent() {
    while (getline(in, currentLine)) {
      preprocessCurrentLine();

      if (currentLine == "{") {
        eventIsRead = true;
        continue;
      }

      if (currentLine == "}") {
        eventIsRead = false;
        return createEventFromMap(); 
      }

      if (!eventIsRead || currentLine == "") {
        continue;
      }

      parseFieldToMap();
    }

    throw CannotReadEvent();
  }
};

int main() {
  vector<Event> events;

  ifstream in("input.txt");
  EventReader eventReader(in);

  while (true) {
    try {
      events.push_back(eventReader.readEvent());
    } catch (CannotReadEvent) {
      break;
    }
  }

  // Сортировка с использованием компоратора
  sort(events.begin(), events.end(), comp);

  // Запись отсортированный событий в файл
  ofstream out("output.txt");
  for (int i = 0; i < events.size(); i++) {
    events[i].printEvent(out);
  }
  out.close();

  return 0;
}
