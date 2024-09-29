#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
using namespace std;

const int maxN = (int)2e7;

// array for input numbers
int A[maxN], n;

int main() {
  int i, j, k;

  freopen("random_num.in", "r", stdin);

  cin >> n;
  for (i = 0; i < n; i++)
    cin >> A[i];

  // perform Bubble-Sort
  for (i = 0; i < n - 1; i++) {
    // A[0... i-1] are sorted
    for (j = 0; j < n - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
      }
    }
  }

  for (i = 0; i < n; i++)
    cout << A[i] << ' ';
  cout << "\n";

  return 0;
}
