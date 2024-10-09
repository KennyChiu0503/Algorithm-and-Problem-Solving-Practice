
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long calculateFinalLength(string s, int m, int k,
                               vector<string> &replacements) {
  vector<long long> length(26);
  for (int i = 0; i < k; ++i) {
    length[i] = 1;
  }

  for (int step = 0; step < m; ++step) {
    vector<long long> newLength(26, 0);

    for (int i = 0; i < k; ++i) {
      long long newLen = 0;
      for (char ch : replacements[i]) {
        newLen += length[ch - 'a'];
        if (newLen >= MOD)
          newLen -= MOD;
      }
      newLength[i] = newLen;
    }

    length = newLength;
  }

  long long finalLength = 0;
  for (char ch : s) {
    finalLength += length[ch - 'a'];
    if (finalLength >= MOD)
      finalLength -= MOD;
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
