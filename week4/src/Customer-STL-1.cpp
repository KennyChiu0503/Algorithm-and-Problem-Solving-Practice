#include <bits/stdc++.h>
using namespace std;

multiset<int> tickets;

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

        auto it = tickets.upper_bound(i);
        if( tickets.size() ==0 || it == tickets.begin() )
            cout << "-1\n";
        else
        {
            cout << *(--it) << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
