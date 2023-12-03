#include <iostream>

using namespace std;

int** allocate_arr(int rows, int cols) {
  int** arr = new int*[rows];
  for (int row = 0; row < rows; ++row) {
    arr[row] = new int[cols];
  }
  return arr;
}

void fill_arr(int** arr, int rows, int cols) {
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      cin >> arr[row][col];
    }
  }
}

void clear_arr(int** arr, int rows) {
  for (int row = 0; row < rows; ++row) {
    delete [] arr[row];
  }
  delete [] arr;
}

void print_arr(int** arr, int rows, int cols) {
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
}

void find_min_row_col(int** arr, int rows, int cols, int &min_row, int &min_col) {
  min_row = 0;
  min_col = 0;

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (arr[min_row][min_col] > arr[row][col]) {
        min_row = row;
        min_col = col;
      }
    }
  }
}

void remove_row(int **arr, int &rows, int del_row) {
  int* del_row_ptr = arr[del_row];

  for (int row = del_row; row < rows - 1; ++row) {
    arr[row] = arr[row + 1];
  }

  --rows;
  delete del_row_ptr;
}

void remove_col(int **arr, int rows, int &cols, int del_col) {
  for (int row = 0; row < rows; ++row) {
    for (int col = del_col; col < cols - 1; ++col) {
      arr[row][col] = arr[row][col + 1];
    }
  }

  --cols;
}

int main() {
  cout << "Введите размерность массива: ";
  int rows, cols;
  cin >> rows >> cols;

  int** arr = allocate_arr(rows, cols);

  cout << "Введите элементы массива: " << endl;
  fill_arr(arr, rows, cols);

  cout << endl;
  
  int min_row, min_col;
  find_min_row_col(arr, rows, cols, min_row, min_col);

  remove_row(arr, rows, min_row);
  remove_col(arr, rows, cols, min_col);

  print_arr(arr, rows, cols);
  clear_arr(arr, rows);

  return 0;
}
