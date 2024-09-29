#include <bits/stdc++.h>
using namespace std;

const int maxN = 20;

int a[maxN], b, n;

int cnt( int level, int val )
{
    if( level == n )
        return val == 0;

    int k = 0;
    for( int i = 0; i*a[level] <= val; i++ )
        k += cnt( level+1, val - i*a[level] );

    return k;
}

int main()
{
    int i,j,k;

    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i];
    cin >> b;

    cout << cnt(0,b) << '\n';

    return 0;
}
