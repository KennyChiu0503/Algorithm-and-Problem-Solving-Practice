#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

vector<pi> pts;

//  return true if va to vb is counter-clockwise order
bool vec_ccw( pi va, pi vb )
{
    return 1LL*va.first*vb.second - 1LL*va.second*vb.first > 0;
}

pi operator-( const pi &a, const pi &b )
{
    return pi(a.first-b.first, a.second-b.second);
}

//

int main()
{
    int i,j,k;
    int a,b,c;

    cin >> j >> k;
    while(j--)
    {
        cin >> a >> b;

        pts.push_back( pi(a,b) );
    }

    while(k--)
    {
        pi pt;

        cin >> pt.first >> pt.second;

        int left = -1, right = pts.size()-1;

        while( left < right - 1 )
        {
            int mid = (left+right)/2;

            if( vec_ccw( pts[mid]-pt, pts[mid+1]-pts[mid] ) )
                left = mid;
            else
                right = mid;
        }

        cout << right+1 << '\n';
    }

    return 0;
}
