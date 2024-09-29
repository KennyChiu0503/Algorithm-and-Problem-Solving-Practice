#include <bits/stdc++.h>
#include <ostream>
using namespace std;

const int maxN = 20;
int a[maxN], b, n;
// count the number of non-negative solutions
//  for aj*xj +...+an*nx = val
int cnt(int level, int val) {
  if (level == n) // x_0, ..., x{n-1} are determined
  {
    return val == 0;
  }

  int i, j, k;
  k = 0;
  for (i = 0; a[level] * i <= val; i++) {
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
  cin >> b;
  cout << cnt(0, b) << endl;
  return 0;
}
