#include <bits/stdc++.h>
#define N 200001
using namespace std;
int n, i, tot, ans, a[N], bz[N], l[N], r[N], dui[N];
void pd(int x, int y) {
  for (int i = x, pl; i < y; i++) {
    pl = bz[a[y] - a[i]];
    if (pl > y && pl <= r[y])
      ans++;
  }
}
void ps(int x, int y) {
  for (int i = y, pl; i > x; i--) {
    pl = bz[a[x] - a[i]];
    if (pl < x && pl >= l[x])
      ans++;
  }
}
int main() {
  int n;
  cin >> n;

  for (i = 1; i <= n; i++) {
    cin >> a[i];
    bz[a[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    while (a[dui[tot]] < a[i] && tot)
      tot--;
    l[i] = dui[tot] + 1;
    dui[++tot] = i;
  }
  tot = 0;
  dui[0] = n + 1;
  for (i = n; i >= 1; i--) {
    while (a[dui[tot]] < a[i] && tot)
      tot--;
    r[i] = dui[tot] - 1;
    dui[++tot] = i;
  }
  for (i = 1; i <= n; i++)
    if (i - l[i] < r[i] - i)
      pd(l[i], i);
    else
      ps(i, r[i]);
  cout << ans << endl;
  return 0;
}
