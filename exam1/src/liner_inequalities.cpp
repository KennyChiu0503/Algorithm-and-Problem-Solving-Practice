#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, b;
  cin >> n;

  // Input a_i
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // Input c_i
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  // Input d_i
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  // Input inequality b
  cin >> b;

  int count = 0;

  // x_1, x_2, ..., x_n
  function<void(int, int)> find_solutions = [&](int idx, int sum) {
    if (idx == n) {
      if (sum <= b) {
        count++;
      }
      return;
    }
    for (int x = c[idx]; x <= d[idx]; ++x) {
      find_solutions(idx + 1, sum + a[idx] * x);
    }
  };

  // Recursion initial sum of 0
  find_solutions(0, 0);

  cout << count << endl;

  return 0;
}
