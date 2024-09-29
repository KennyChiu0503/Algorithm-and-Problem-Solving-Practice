#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
};

// Function to compute the cross product of vectors (p2 - p1) and (q - p1)
long long crossProduct(const Point &p1, const Point &p2, const Point &q) {
  return (p2.x - p1.x) * (q.y - p1.y) - (p2.y - p1.y) * (q.x - p1.x);
}

// Function to perform binary search to find the tangent point for the query
// point
int findTangentPoint(const vector<Point> &curve, const Point &query) {
  int low = 1, high = curve.size() - 1;

  while (low < high) {
    int mid = (low + high) / 2;
    long long cross = crossProduct(curve[mid], curve[mid + 1], query);

    if (cross > 0) {
      low = mid + 1; // query is above the segment, move right
    } else {
      high = mid; // query is below the segment, move left
    }
  }

  return low;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Point> curve(n);

  // Input convex curve points
  for (int i = 0; i < n; ++i) {
    cin >> curve[i].x >> curve[i].y;
  }

  // Input query points
  vector<Point> queries(m);
  for (int i = 0; i < m; ++i) {
    cin >> queries[i].x >> queries[i].y;
  }

  // Output tangent points for each query
  for (const auto &query : queries) {
    cout << findTangentPoint(curve, query) + 1
         << endl; // +1 for 1-based indexing
  }

  return 0;
}
