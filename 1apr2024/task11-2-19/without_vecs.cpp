#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct SquareMatrix {
  int n;
  int** elements;
  void read(istream& in);
  void write(ostream& out);
  int** sideDiag(int distance);
};

void SquareMatrix::read(istream &in) {
  in >> n;
  elements = new int*[n];
  for (int i = 0; i < n; i++) {
    int* row = new int[n];
    for (int j = 0; j < n; j++) {
      int el;
      in >> el;
      row[j] = el;
    }
    elements[i] = row;
  }
}

void SquareMatrix::write(ostream &out) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      out << elements[i][j] << ' ';
    }
    out << endl;
  }
}

int** SquareMatrix::sideDiag(int distance) { 
  // distance > 0 - выше побочной диагонали
  // distance < 0 - ниже побочной диагонали
  // distance = 0 - побочная диагональ

  int diagn = n - abs(distance);
  int** diag = new int*[n];
  for (int i = 0; i < diagn; i++) {
    if (distance > 0) {
      diag[i] = &elements[i][i + abs(distance)];
    } else {
      diag[i] = &elements[i + abs(distance)][i];
    }
  }
  return diag;
}

enum SortMethod {
  Asc, // по возрастанию
  Desc, // по убыванию
};

void sort(int** arr, int n, SortMethod method) {
  int *tmp;
  int boundary, boundaryidx;

  for (int i = 0; i < n - 1; i++) {
    boundaryidx = i;
    boundary = *arr[i];
    for (int j = i + 1; j < n; j++) {
      if ((method == Asc) ? (*arr[j] < boundary) : (*arr[j] > boundary)) {
        boundary = *arr[j];
        boundaryidx = j;
      }
    }
    swap(*arr[i], *arr[boundaryidx]);
  }
}

int main() {
  SquareMatrix mat;

  ifstream in("input.txt");
  mat.read(in);
  in.close();

  for (int i = 1; i <= mat.n - 1; i++) {
    sort(mat.sideDiag(i), mat.n - abs(i), Desc);
  }

  for (int i = -mat.n + 1; i <= -1; i++) {
    sort(mat.sideDiag(i), mat.n - abs(i), Asc);
  }

  ofstream out("output.txt");
  mat.write(out);
  out.close();

  return 0;
}
