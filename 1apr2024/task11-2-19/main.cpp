#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct SquareMatrix {
  int n;
  vector<vector<int>> elements;
  void read(istream& in);
  void write(ostream& out);
  vector<int*> sideDiag(int distance);
};

void SquareMatrix::read(istream &in) {
  in >> n;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < n; j++) {
      int el;
      in >> el;
      row.push_back(el);
    }
    elements.push_back(row);
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

vector<int*> SquareMatrix::sideDiag(int distance) { 
  // distance > 0 - выше побочной диагонали
  // distance < 0 - ниже побочной диагонали
  // distance = 0 - побочная диагональ

  int diagn = n - abs(distance);
  vector<int*> diag;
  for (int i = 0; i < diagn; i++) {
    if (distance > 0) {
      diag.push_back(&elements[i][i + abs(distance)]);
    } else {
      diag.push_back(&elements[i + abs(distance)][i]);
    }
  }
  return diag;
}

enum SortMethod {
  Asc, // по возрастанию
  Desc, // по убыванию
};

void sort(vector<int*> vec, SortMethod method) {
  int *tmp;
  int boundary, boundaryidx;

  for (int i = 0; i < vec.size() - 1; i++) {
    boundaryidx = i;
    boundary = *vec[i];
    for (int j = i + 1; j < vec.size(); j++) {
      if ((method == Asc) ? (*vec[j] < boundary) : (*vec[j] > boundary)) {
        boundary = *vec[j];
        boundaryidx = j;
      }
    }
    swap(*vec[i], *vec[boundaryidx]);
  }
}

int main() {
  SquareMatrix mat;

  ifstream in("input.txt");
  mat.read(in);
  in.close();

  for (int i = 1; i <= mat.n - 1; i++) {
    sort(mat.sideDiag(i), Desc);
  }

  for (int i = -mat.n + 1; i <= -1; i++) {
    sort(mat.sideDiag(i), Asc);
  }

  ofstream out("output.txt");
  mat.write(out);
  out.close();

  return 0;
}
