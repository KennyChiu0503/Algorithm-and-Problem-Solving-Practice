#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// Function to count special segments
int countSpecialSegments(const vector<int> &perm, int n) {
  int specialCount = 0;

  // Deque to maintain the maximum in the current range
  deque<int> dq;

  // Iterate over every possible starting point 'l'
  for (int l = 0; l < n; ++l) {
    // Clear deque for new segment
    dq.clear();

    // Iterate over all possible ending points 'r' from l to n-1
    for (int r = l; r < n; ++r) {
      // Maintain maximum element in the deque
      while (!dq.empty() && dq.back() < perm[r]) {
        dq.pop_back();
      }
      dq.push_back(perm[r]);

      // The maximum in the current range [l, r] is dq.front()
      if (perm[l] + perm[r] == dq.front()) {
        ++specialCount;
      }
    }
  }

  return specialCount;
}

int main() {
  int n;
  cin >> n;
  vector<int> perm(n);

  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
  }

  cout << countSpecialSegments(perm, n) << endl;

  return 0;
}
