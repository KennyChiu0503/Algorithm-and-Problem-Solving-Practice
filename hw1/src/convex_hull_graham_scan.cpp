#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
  int idx;
};

// Function to compute the cross product of vectors OA and OB
long long cross(const Point &O, const Point &A, const Point &B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Function to compute the squared distance between two points
long long dist(const Point &A, const Point &B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

// Function to compute the Convex Hull using Graham Scan
vector<int> grahamScan(vector<Point> &points) {
  int n = points.size();
  if (n <= 1)
    return {};

  // Step 1: Find the point with the lowest y-coordinate (and leftmost in case
  // of tie)
  swap(points[0], *min_element(points.begin(), points.end(),
                               [](const Point &a, const Point &b) {
                                 return a.y < b.y || (a.y == b.y && a.x < b.x);
                               }));

  Point p0 = points[0];

  // Step 2: Sort the points based on polar angle with respect to p0
  sort(points.begin() + 1, points.end(), [p0](const Point &a, const Point &b) {
    long long cp = cross(p0, a, b);
    if (cp == 0) { // Collinear points: closer point comes first
      return dist(p0, a) < dist(p0, b);
    }
    return cp > 0;
  });

  // Step 3: Handle collinear points at the end (include only the farthest one)
  int m = 1; // Size of the hull
  for (int i = 1; i < n; ++i) {
    while (i < n - 1 && cross(p0, points[i], points[i + 1]) == 0) {
      ++i; // Skip over collinear points
    }
    points[m++] = points[i]; // Add the farthest point in the collinear group
  }

  // Step 4: Graham Scan algorithm
  vector<Point> hull = {points[0], points[1]};
  for (int i = 2; i < m; ++i) {
    while (hull.size() > 1 &&
           cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }

  // Step 5: Extract the indices of points in the hull
  vector<int> result;
  for (const Point &p : hull) {
    result.push_back(p.idx);
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<Point> points(n);

  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
    points[i].idx = i + 1; // Store the original index
  }

  // Compute the convex hull
  vector<int> hull = grahamScan(points);

  // Output the result
  cout << hull.size() + 1 << endl;
  for (int i : hull) {
    cout << i << " ";
  }
  cout << hull[0] << endl; // Close the loop by repeating the first point

  return 0;
}

