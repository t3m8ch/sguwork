#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream out("f.dat", ios::binary);

  int max_n;
  cin >> max_n;

  double reverse_n;

  for (double curr_n = 1; curr_n <= max_n; ++curr_n) {
    reverse_n = 1 / curr_n;
    out.write((char *)&(reverse_n), sizeof(reverse_n));
  }

  out.close();

  ifstream in("f.dat", ios::binary);

  int i = 0;

  while (true) {
    in.seekg(sizeof(double) * 2, ios::cur);

    if (in.peek() == EOF) {
      break;
    }

    in.read((char *)&(reverse_n), sizeof(double));
    
    cout <<  reverse_n << ' ';
    i++;
  }

  cout << endl;

  in.close();

  return 0;
}