#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)2e5;
typedef array<long long, 3> pt;

int n;
pt pts[maxN];

int num_hull;
int hull_idx[maxN];

long long cross_pd(pt &va, pt &vb) { return va[0] * vb[1] - va[1] * vb[0]; }

long long inner_pd(pt &v) { return v[0] * v[0] + v[1] * v[1]; }

pt ref_pt;

bool pt_cmp(pt &a, pt &b) {
  long long cr_pd = cross_pd(a, b);

  long long inn_pd_a = inner_pd(a);
  long long inn_pd_b = inner_pd(b);

  return cr_pd > 0 || (cr_pd == 0 && inn_pd_a < inn_pd_b);
}

int main() {
  int i, j, k;
  int a, b, c;

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> pts[i][0] >> pts[i][1];
    pts[i][2] = i + 1;
  }

  ref_pt = pts[0];
  for (i = 1; i < n; i++) {
    if (pts[i][0] < ref_pt[0] ||
        (pts[i][0] == ref_pt[0] && pts[i][1] < ref_pt[1]))
      ref_pt = pts[i];
  }

  for (i = 0; i < n; i++) {
    pts[i][0] -= ref_pt[0];
    pts[i][1] -= ref_pt[1];
  }

  sort(pts, pts + n, pt_cmp);
  for (i = 0; i < n; i++) {
    cout << pts[i][2] << " ";
  }
  cout << endl;
  return 0;
}

