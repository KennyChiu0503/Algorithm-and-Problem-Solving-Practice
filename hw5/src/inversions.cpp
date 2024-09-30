#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count inversions
long long merge_and_count(vector<int> &arr, vector<int> &temp, int left,
                          int mid, int right) {
  int i = left;    // Starting index for left subarray
  int j = mid + 1; // Starting index for right subarray
  int k = left;    // Starting index to be sorted
  long long inv_count = 0;

  // Merge the two subarrays while counting inversions
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count += (mid - i + 1); // Count the inversions
    }
  }

  // Copy the remaining elements of left subarray, if any
  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  // Copy the remaining elements of right subarray, if any
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  // Copy the sorted subarray into the original array
  for (i = left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return inv_count;
}

// Recursive function to count inversions using merge sort
long long merge_sort_and_count(vector<int> &arr, vector<int> &temp, int left,
                               int right) {
  long long inv_count = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Count inversions in the left half
    inv_count += merge_sort_and_count(arr, temp, left, mid);

    // Count inversions in the right half
    inv_count += merge_sort_and_count(arr, temp, mid + 1, right);

    // Count inversions during the merge step
    inv_count += merge_and_count(arr, temp, left, mid, right);
  }
  return inv_count;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Temporary array to be used during merge sort
  vector<int> temp(n);

  // Count inversions using merge sort
  long long result = merge_sort_and_count(arr, temp, 0, n - 1);

  // Output the result
  cout << result << endl;

  return 0;
}
