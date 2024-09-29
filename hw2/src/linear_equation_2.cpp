#include <bits/stdc++.h>
using namespace std;

const int maxN = 20;
int a[maxN], c[maxN], x[maxN], b, n;
// count the number of non-negative solutions
//  for aj*xj +...+an*nx = val
int cnt(int level, int val) {
  if (level == n) // x_0, ..., x{n-1} are determined
  {
    if (val == 0) {
      for (int i = 0; i < n; i++) {
        if (x[i] < c[i])
          return 0;
      }
      // return x[level] > c[level];
    }
    return val == 0;
  }

  int i, j, k;
  k = 0;
  for (i = 0; a[level] * i <= val; i++) {
    x[level] = i;
    k += cnt(level + 1, val - a[level] * i);
  }
  return k;
}

int main() {
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> c[i];
  }
  cin >> b;
  cout << cnt(0, b) << endl;
  return 0;
}
