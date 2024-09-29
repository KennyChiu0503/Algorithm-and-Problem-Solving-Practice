#include <bits/stdc++.h>
using namespace std;

struct cmp_obj
{
    bool operator() ( const int &a, const int &b ) const
    {
        return a > b;
    }
};

multiset< int, cmp_obj > tickets;

int main()
{
    int i,j,k;

    cin >> k >> j;
    while(k--)
    {
        cin >> i;
        tickets.insert(i);
    }

    while(j--)
    {
        cin >> i;

        auto it = tickets.lower_bound(i);
        if( it == tickets.end() )
            cout << "-1\n";
        else
            cout << *it << "\n", tickets.erase(it);
    }

    return 0;
}
