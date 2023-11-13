#include <iostream>

using namespace std;

void print_arr(double *arr, int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << "\t";
  }
  cout << endl;
}

int main() {
  // Получение размера матрицы
  int n;
  cout << "Введите размер квадратной матрицы: ";
  cin >> n;

  // Выделение памяти под матрицу
  double **a = new double *[n];
  for (int i = 0; i < n; ++i) {
    a[i] = new double [n];
  }

  // Ввод значений
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << "Введите значение a[" << i << "][" << j << "] = ";
      cin >> *(*(a + i) + j);
    }
  }

  // Ввод степени
  int g;
  cout << "В какую степень вы хотите возвести матрицу: ";
  cin >> g;

  // Выделение матрицы под новую матрицу
  double **b = new double *[n];
  for (int i = 0; i < n; ++i) {
    b[i] = new double [n];
  }

  // Возведение в степень
  for (int m = 0; m < g - 1; ++m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[i][j] = 0;
        for (int k = 0; k < n; ++k) {
          b[i][j] += a[i][k] * a[k][j];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = *(*(b + i) + j);
      }
    }
  }

  // Вывод матрицы на экран
  for (int i = 0; i < n; ++i) {
    print_arr(b[i], n);
  }
  
  // Очистка памяти
  for (int i = 0; i < n; ++i) {
    delete [] a[i];
  }
  delete [] a;
}

