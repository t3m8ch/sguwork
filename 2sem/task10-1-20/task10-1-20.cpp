#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {
  int x, y, z;
};

struct Triangle {
  Point p1, p2, p3;
  double perimeter;
  void write(ofstream& out);
};

void Triangle::write(ofstream& out) {
  out << p1.x << ' ' << p1.y << ' ' << p1.z << endl
      << p2.x << ' ' << p2.y << ' ' << p2.z << endl
      << p3.x << ' ' << p3.y << ' ' << p3.z << endl;
}

double length(Point p1, Point p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

Triangle triangle_from_points(Point p1, Point p2, Point p3) {
  double perim = length(p1, p2) + length(p2, p3) + length(p1, p3);
  return { p1, p2, p3, perim };
}

int main() {
  ifstream in("input.txt");

  Point points[100];
  int n = 0;

  while (in >> points[n].x >> points[n].y >> points[n].z) {
    ++n;
  }

  in.close();

  Triangle min_triangle = triangle_from_points(points[0], points[1], points[2]);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        bool unique_points = (i != j) && (j != k) && (i != k);
        if (!unique_points) {
          continue;
        }

        Triangle curr_triangle = triangle_from_points(points[i], points[j], points[k]);
        if (curr_triangle.perimeter < min_triangle.perimeter) {
          min_triangle = curr_triangle;
        }
      }
    }
  }

  ofstream out("output.txt");
  min_triangle.write(out);

  return 0;
}
