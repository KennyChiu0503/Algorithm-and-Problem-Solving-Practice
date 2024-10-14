#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5;

struct node {
    int left, right, mid;
    int rmq;
    node *lc, *rc;
} nodes[maxN*2], *last = nodes;

int A[maxN], n;

//
//  to build a segment tree on [ell,r] at node root
//
void build_tree( node *root, int ell, int r )
{
    root->left = ell;
    root->right = r;
    root->mid = (ell+r)/2;

    if( ell == r )
        root->rmq = A[ell];
    else
    {
        build_tree( root->lc = last++, ell, root->mid);
        build_tree( root->rc = last++, root->mid+1, r);

        root->rmq = min( root->lc->rmq,
                         root->rc->rmq );
    }
}

//
//  return the minimum element
//  in the intersection of I_r and [ell,r]
//
int query_tree( node *root, int ell, int r )
{
    if( ell <= root->left && root->right <= r )
        return root->rmq;

    if( r <= root->mid )
        return query_tree(root->lc, ell, r);
    else if( root->mid < ell )
        return query_tree(root->rc, ell, r);

    return min( query_tree(root->lc, ell, r),
                query_tree(root->rc, ell, r) );
}

//
//  to be called after the value of a[k] is updated
//
void update_tree( node *root, int k )
{
    if( root->left == k && root->right == k )
        root->rmq = A[k];

    if( k <= root->mid )
        update_tree(root->lc, k);
    else
        update_tree(root->rc, k);

    root->rmq = min( root->lc->rmq,
                     root->rc->rmq );
}

//

int main()
{
    int i,j,k;
    string tmp;

    // read the input array A
    cin >> n;
    for(i=0;i<n;i++)
        cin >> A[i];

    // build the segment tree for [0,n-1] at root node 1
    build_tree(last++,0,n-1);

    // process queries
    cin >> k;
    while(k--)
    {
        cin >> tmp >> i >> j;

        if( tmp == "rmq" )
            cout << query_tree(nodes,i,j);
        else if( tmp == "update" )
        {
            A[i] = j;
            update_tree(nodes,i);
        }
    }

    return 0;
}
