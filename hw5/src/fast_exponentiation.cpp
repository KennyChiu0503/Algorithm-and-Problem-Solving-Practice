#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Binary exponentiation
long long power_mod(long long a, long long b, int mod) {
  long long result = 1;
  a = a % mod;

  while (b > 0) {
    if (b % 2 == 1) {
      result = (result * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }

  return result;
}

int main() {
  int test_case;
  cin >> test_case;

  while (test_case--) {
    long long a, b;
    cin >> a >> b;
    cout << power_mod(a, b, MOD) << endl;
  }

  return 0;
}

