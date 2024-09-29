#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<string> board(N);
bool col[N], diag1[2 * N], diag2[2 * N];
int solutions = 0;

void placeQueens(int row) {
  if (row == N) {
    solutions++;
    return;
  }

  for (int c = 0; c < N; ++c) {
    if (board[row][c] == '.' && !col[c] && !diag1[row - c + N - 1] &&
        !diag2[row + c]) {
      col[c] = diag1[row - c + N - 1] = diag2[row + c] = true;
      placeQueens(row + 1);
      col[c] = diag1[row - c + N - 1] = diag2[row + c] = false;
    }
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    cin >> board[i];
  }

  fill(col, col + N, false);
  fill(diag1, diag1 + 2 * N, false);
  fill(diag2, diag2 + 2 * N, false);

  placeQueens(0);

  cout << solutions << endl;

  return 0;
}
