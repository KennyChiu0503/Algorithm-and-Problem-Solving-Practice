#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, num;

  cin >> N;

  unordered_map<int, int> frequency;

  for (int i = 0; i < N; i++) {
    cin >> num;
    frequency[num]++;
  }

  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> num;
    if (frequency[num])
      cout << "Found!" << endl;
    else
      cout << "not found" << endl;
  }

  return 0;
}
