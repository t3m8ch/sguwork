#include <iostream>

using namespace std;

template <typename T> T** input_arr(int n, int m) {
  T **arr = new T *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new T[n];
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  return arr;
}

template <typename T> void print_arr(T **arr, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

template <typename T> T avg_neg(T **arr, int n, int m) {
  double sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] < 0) {
        count++;
        sum += arr[i][j];
      }
    }
  }
  return sum / count;
}

int main() {
  int n, m;
  cout << "Размерность массива: ";
  cin >> n >> m;

  cout << "Целочисленный массив:" << endl;
  int **int_arr = input_arr<int>(n, m);
  cout << "Среднее арифметическое отрицательных элементов: " << avg_neg(int_arr, n, m) << endl;

  cout << "Вещественный массив:" << endl;
  double **double_arr = input_arr<double>(n, m);
  cout << "Среднее арифметическое отрицательных элементов: " << avg_neg(double_arr, n, m) << endl;

  return 0;
}
