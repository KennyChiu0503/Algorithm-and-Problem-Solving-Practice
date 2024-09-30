#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate the final length of the string after m operations
long long calculateFinalLength(string s, int m, int k,
                               vector<string> &replacements) {
  // Initialize the length array for each character (a-z)
  vector<long long> length(26);

  // Initially, the length of each character is 1 (each character represents
  // itself)
  for (int i = 0; i < k; ++i) {
    length[i] = 1;
  }

  // Perform m operations
  for (int step = 0; step < m; ++step) {
    vector<long long> newLength(26, 0);

    // Update the length of each character based on the replacement rules
    for (int i = 0; i < k; ++i) {
      long long newLen = 0;
      for (char ch : replacements[i]) {
        newLen = (newLen + length[ch - 'a']) % MOD;
      }
      newLength[i] = newLen;
    }

    // Update the length array with the new lengths
    length = newLength;
  }

  // Calculate the length of the final string
  long long finalLength = 0;
  for (char ch : s) {
    finalLength = (finalLength + length[ch - 'a']) % MOD;
  }

  return finalLength;
}

int main() {
  int n, m, k;
  cin >> n >> m;

  string s;
  cin >> s;

  cin >> k;

  vector<string> replacements(k);
  for (int i = 0; i < k; ++i) {
    cin >> replacements[i];
  }

  cout << calculateFinalLength(s, m, k, replacements) << endl;

  return 0;
}
