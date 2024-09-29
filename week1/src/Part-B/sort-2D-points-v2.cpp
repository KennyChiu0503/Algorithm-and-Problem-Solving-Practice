#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5 + 1;

int n;
array<array<int, 2>, maxN> points;

//

bool cmp(array<int, 2> &a, array<int, 2> &b) {
  if (a[0] == b[0])
    return a[1] > b[1];
  else
    return a[0] > b[0];

  // return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

//

int main() {
  int i, j, k;

  cin >> n;
  for (i = 0; i < n; i++)
    cin >> points[i][0] >> points[i][1];

  sort(points.begin(), points.begin() + n, cmp);

  for (i = 0; i < n; i++)
    cout << points[i][0] << " " << points[i][1] << endl;

  return 0;
}
