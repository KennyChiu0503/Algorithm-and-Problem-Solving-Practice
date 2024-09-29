#include <bits/stdc++.h>
using namespace std;

const int maxN = 10;

int n;
int used[maxN], permut[maxN];

void gen_permut( int level )
{
    int i,j,k;

    if( level == n )
    {
        // we have generated a permutation.
        // print it.

        for(i=0;i<n;i++)
            cout << permut[i]+1 << ' ';
        cout << "\n";

        return;
    }

    // try all possible numbers for position 'level'
    // for each such possibility,
    // recurse to generate all possibilities.

    for(i=0;i<n;i++)
    {
        if( used[i] )
            continue;

        // i has not been used yet
        used[i] = 1;
        permut[level] = i;

        gen_permut(level+1);

        used[i] = 0;
    }

    return;
}

int main()
{
    cin >> n;

    gen_permut(0);

    return 0;
}
