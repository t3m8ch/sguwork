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

void sortStudentByGradesSum(Student* students, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (students[j].getSumOfGrades() > students[j - 1].getSumOfGrades()) {
        swap(students[j], students[j - 1]);
      }
    }
  }
}


int linesCount(ifstream &in) {
  int i = 0;
  string s;
  while (getline(in, s)) { 
    i++; 
  }  

  in.clear();
  in.seekg(0);

  return i;
}

int main() {
  ifstream in("input.txt");
  int n = linesCount(in) - 1;

  Student* students = new Student[n];

  int groupNumber;
  in >> groupNumber;
  
  for (int i = 0; i < n; i++) {
    Student student;
    student.read(in);
    students[i] = student;
  }

  in.close();

  sortStudentByGradesSum(students, n);

  ofstream out("output.txt");
  out << groupNumber << endl;

  for (int i = 0; i < n; i++) {
    students[i].writeWithGradesSum(out);
  }

  out.close();

  return 0;
}
