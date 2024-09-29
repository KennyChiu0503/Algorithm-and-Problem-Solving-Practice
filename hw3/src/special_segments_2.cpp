#include <bits/stdc++.h>
using namespace std;

// Function to count special segments
int countSpecialSegments(const vector<int> &perm, int n) {
  int specialCount = 0;

  // Iterate over every possible starting point 'l'
  for (int l = 0; l < n; ++l) {
    multiset<int>
        windowElements; // Multiset to maintain elements in the current window

    // Iterate over all possible ending points 'r' from l to n-1
    for (int r = l; r < n; ++r) {
      // Insert the current element into the multiset
      windowElements.insert(perm[r]);

      // The maximum element in the current range [l, r] is the largest element
      // in the multiset
      int maxInWindow =
          *windowElements
               .rbegin(); // Last element in sorted order is the maximum

      // Check if p[l] + p[r] equals the maximum element
      if (perm[l] + perm[r] == maxInWindow) {
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

  // Input the permutation
  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
  }

  // Output the number of special segments
  cout << countSpecialSegments(perm, n) << endl;

  return 0;
}

