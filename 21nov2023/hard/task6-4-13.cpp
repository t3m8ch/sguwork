#include <iostream>

using namespace std;

int** allocate_arr(int n) {
  int** arr = new int*[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[n];
  }
  return arr;
}

void fill_arr(int** arr, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
}

void clear_arr(int** arr, int n) {
  for (int i = 0; i < n; ++i) {
    delete [] arr[i];
  }
  delete [] arr;
}

void print_arr(int* arr, int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Введите размер массива: ";
  cin >> n;

  int** arr = allocate_arr(n);

  cout << "Введите элементы массива:" << endl;
  fill_arr(arr, n);

  int* b = new int[n]; 
  for (int i = 0; i < n; ++i) {
    b[i] = -1;
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] < 0) {
        b[i] = j;
        break;
      }
    }
  }

  print_arr(b, n);

  clear_arr(arr, n);

  return 0;
}

