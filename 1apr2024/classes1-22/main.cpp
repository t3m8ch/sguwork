#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  string getName() { return name; }
  void setName(string _name) { name = _name; }

  Organizer getOrganizer() { return organizer; }
  void setOrganizer(Organizer _organizer) { organizer = _organizer; }

  DateTime getDateTime() { return dateTime; }
  void setDateTime(DateTime _dateTime) { dateTime = _dateTime; }

  double getCost() { return cost; }
  void setCost(double _cost) { cost = _cost; }

  static int getObjectsCount() { return Event::objectsCount; }

  void printEvent() {
    cout << "Event(name=\"" << name << "\", organizer=Organizer(name=\""
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

int main() {
  vector<Event> events = {
    Event(),
    Event(
      "A Event 2",
      Organizer("Вторая компания", "ул. Столыпина", "+7 800 000-00-00"),
      DateTime(2023, 1, 1, 0, 0),
      2000
    ),
    Event(
      "Event 3",
      Organizer("Вторая компания", "ул. Столыпина", "+7 800 000-00-00"),
      DateTime(2024, 2, 1, 0, 0),
      2000
    ),
    Event(
      "Event 4",
      Organizer("Вторая компания", "ул. Столыпина", "+7 800 000-00-00"),
      DateTime(2024, 1, 2, 0, 0),
      2000
    ),
  };

  cout << "Кол-во объектов: " << Event::getObjectsCount() << endl << endl;

  sort(events.begin(), events.end());
  for (int i = 0; i < events.size(); i++) {
    events[i].printEvent();
  }

  events[2].setDateTime(DateTime(1999, 1, 1, 20, 0));
  events[0].setName("Event 2");
  events[1].setCost(10000);
  events[1].setOrganizer(Organizer("Orga", "addr", "888-888"));
  sort(events.begin(), events.end());

  cout << endl;
  for (int i = 0; i < events.size(); i++) {
    events[i].printEvent();
  }

  cout << endl;
  cout << "events[0].getName() = " << events[0].getName() << endl;
  cout << "events[0].getCost() = " << events[0].getCost() << endl;

  return 0;
}
