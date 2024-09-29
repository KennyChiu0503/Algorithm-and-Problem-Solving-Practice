#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)2e7;

// array for input numbers
int A[maxN], n;
int temp[maxN];

void Merge(int left, int mid, int right) {
  int i, j, k;

  for (i = left; i <= right; i++)
    temp[i] = A[i];

  for (i = left, j = mid + 1, k = left; i <= mid && j <= right;)
    A[k++] = (temp[i] < temp[j]) ? temp[i++] : temp[j++];

  while (i <= mid)
    A[k++] = temp[i++];

  while (j <= right)
    A[k++] = temp[j++];
}

void MergeSort(int left, int right) {
  if (left == right)
    return;

  int mid = (left + right) / 2;

  MergeSort(left, mid);
  MergeSort(mid + 1, right);

  Merge(left, mid, right);
}

int main() {
  int i, j, k;

  // freopen("random_num.in", "r", stdin);

  cin >> n;
  for (i = 0; i < n; i++)
    cin >> A[i];

  // perform Merge-Sort
  MergeSort(0, n - 1);

  for (i = 0; i < n; i++)
    cout << A[i] << ' ';
  cout << "\n";

  return 0;
}
