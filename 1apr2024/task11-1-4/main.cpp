#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
  string name;
  string surname;
  string patronymic;
  int birthYear;
  int grades[5];

  void read(istream &in);
  void writeWithGradesSum(ostream &out);
  int getSumOfGrades();
};

void Student::read(istream &in) {
  in >> surname >> name >> patronymic >> birthYear;
  for (int i = 0; i < 5; i++) {
    in >> grades[i];
  }
}

void Student::writeWithGradesSum(ostream &out) {
  out << surname << ' ' << name << ' ' << patronymic << ' ' << birthYear << ' ' << getSumOfGrades() << endl;
}

int Student::getSumOfGrades() { 
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += grades[i];
  }
  return sum;
}

void sortStudentByGradesSum(vector<Student> &students) {
  for (int i = 0; i < students.size() - 1; i++) {
    for (int j = students.size() - 1; j > i; j--) {
      if (students[j].getSumOfGrades() > students[j - 1].getSumOfGrades()) {
        swap(students[j], students[j - 1]);
      }
    }
  }
}

int main() {
  vector<Student> students;
  ifstream in("input.txt");

  int groupNumber;
  in >> groupNumber;

  while (in.peek() != EOF) {
    Student student;
    student.read(in);
    students.push_back(student);
  }

  in.close();

  sortStudentByGradesSum(students);

  ofstream out("output.txt");
  out << groupNumber << endl;

  for (int i = 0; i < students.size(); i++) {
    students[i].writeWithGradesSum(out);
  }

  out.close();

  return 0;
}
