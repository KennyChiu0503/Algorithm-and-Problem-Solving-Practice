#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, M, num;

  cin >> N;

  map<int, int> frequency;

  // Input the N integers in the database and update their frequency
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

