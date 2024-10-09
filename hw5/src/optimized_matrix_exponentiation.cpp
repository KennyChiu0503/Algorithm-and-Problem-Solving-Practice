
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to multiply two matrices modulo MOD
vector<vector<long long>> multiplyMatrix(const vector<vector<long long>> &a,
                                         const vector<vector<long long>> &b,
                                         int k) {
  vector<vector<long long>> result(k, vector<long long>(k, 0));

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int l = 0; l < k; ++l) {
        result[i][j] = (result[i][j] + a[i][l] * b[l][j] % MOD) % MOD;
      }
    }
  }
  return result;
}

// Function to exponentiate a matrix by an integer exponent
vector<vector<long long>> matrixExponentiate(vector<vector<long long>> base,
                                             int exp, int k) {
  // Identity matrix
  vector<vector<long long>> result(k, vector<long long>(k, 0));
  for (int i = 0; i < k; ++i)
    result[i][i] = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result = multiplyMatrix(result, base, k);
    }
    base = multiplyMatrix(base, base, k);
    exp /= 2;
  }
  return result;
}

long long calculateFinalLength(string s, int m, int k,
                               vector<string> &replacements) {
  // Create the transformation matrix
  vector<vector<long long>> transformationMatrix(k, vector<long long>(k, 0));

  for (int i = 0; i < k; ++i) {
    for (char ch : replacements[i]) {
      transformationMatrix[ch - 'a'][i] += 1;
    }
  }

  // Exponentiate the matrix to get the transformation after m steps
  vector<vector<long long>> poweredMatrix =
      matrixExponentiate(transformationMatrix, m, k);

  // Calculate initial length vector
  vector<long long> initialLength(k, 0);
  for (char ch : s) {
    initialLength[ch - 'a'] += 1;
  }

  // Apply the powered matrix to the initial lengths
  vector<long long> finalLength(k, 0);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      finalLength[i] =
          (finalLength[i] + poweredMatrix[i][j] * initialLength[j] % MOD) % MOD;
    }
  }

  // Sum up the final lengths to get the total length
  long long totalLength = 0;
  for (int i = 0; i < k; ++i) {
    totalLength = (totalLength + finalLength[i]) % MOD;
  }

  return totalLength;
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
