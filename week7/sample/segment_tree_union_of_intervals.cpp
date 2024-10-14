#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5;

struct node {
    int left, right, mid;
    int cnt; // number of times [left,right] is stored
    int len; // length of union of segments within [left,right]
    node *lc, *rc;
} nodes[maxN*2], *last = nodes;
