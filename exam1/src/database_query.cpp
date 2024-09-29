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
    cout << frequency[num] << endl;
  }

  return 0;
}
