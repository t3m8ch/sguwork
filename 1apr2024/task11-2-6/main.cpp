#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[low];
  int i = low + 1;
  int j = high;
  while (true) {
    while (i <= j && arr[i] <= pivot) {
      i++;
    }
    while (i <= j && arr[j] > pivot) {
      j--;
    }

    if (i <= j) {
      swap(arr[i], arr[j]);
    } else {
      swap(arr[low], arr[j]);
      return j;
    }
  }
}

class SquareMatrix {
private:
  int _size;
  vector<vector<int>> _elements;

  void _readFromStream(istream& in) {
    in >> _size;
    for (int i = 0; i < _size; i++) {
      vector<int> row;
      for (int j = 0; j < _size; j++) {
        int el;
        in >> el;
        row.push_back(el);
      }
      _elements.push_back(row);
    }
  }

  void _quickSort(int low, int high, int col) {
    if (low < high) {
      int pivotIndex = _partition(low, high, col);
      _quickSort(low, pivotIndex - 1, col);
      _quickSort(pivotIndex + 1, high, col);
    }
  }

  int _partition(int low, int high, int col) {
    int pivot = _elements[low][col];
    int i = low + 1;
    int j = high;

    while (true) {
      while (i <= j && _elements[i][col] <= pivot) {
        i++;
      }
      while (i <= j && _elements[j][col] > pivot) {
        j--;
      }

      if (i <= j) {
        swap(_elements[i][col], _elements[j][col]);
      } else {
        swap(_elements[low][col], _elements[j][col]);
        return j;
      }
    }
  }
public:
  SquareMatrix(istream& in) {
    _readFromStream(in);
  }

  const vector<vector<int>>& getElements() const {
    return _elements;
  }

  void writeToStream(ostream& out) const {
    for (int i = 0; i < _size; i++) {
      for (int j = 0; j < _size; j++) {
        out << _elements[i][j] << ' ';
      }
      out << endl;
    }
  }

  void sortColumn(int col) {
    _quickSort(0, _size - 1, col);
  }

  void sortAllColumns() {
    for (int i = 0; i < _size; i++) {
      sortColumn(i);
    }
  }
};

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  SquareMatrix mat(in);
  mat.sortAllColumns();
  mat.writeToStream(out);

  return 0;
}
