#include <bits/stdc++.h>
using namespace std;

struct Vector {
  long long x, y;

  long long lengthSquared() const { return x * x + y * y; }
};

long long crossProduct(const Vector &u, const Vector &v) {
  return u.x * v.y - u.y * v.x;
}

bool compareVectors(const Vector &u, const Vector &v) {
  long long cross = crossProduct(u, v);

  // If cross product is positive, u is counterclockwise to v
  if (cross > 0)
    return true;

  // If cross product is negative, u is clockwise to v
  if (cross < 0)
    return false;

  // If cross product is zero, vectors are parallel, compare their lengths
  return u.lengthSquared() < v.lengthSquared();
}

int main() {
  Vector u, v;

  cin >> u.x >> u.y;

  cin >> v.x >> v.y;

  if (compareVectors(u, v)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
