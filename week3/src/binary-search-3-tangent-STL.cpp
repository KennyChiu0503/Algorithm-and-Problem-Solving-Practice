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

struct tagent_cmp
{
    bool operator () ( const pi &p_c, const pi &pt ) const
    {
        const pi *it = &p_c;

        return vec_ccw( p_c - pt, *(it+1) - p_c );
    }
};

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

        auto it = lower_bound( pts.begin(), pts.end()-1, pt, tagent_cmp() );

        cout << it-pts.begin()+1 << '\n';
    }

    return 0;
}
