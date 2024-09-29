#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main()
{
    int i,j,k;

    cin >> k;
    while(k--)
    {
        cin >> j;

        s.insert(j);
    }

    cin >> k;
    while(k--)
    {
        cin >> j;

        if( s.find(j) != s.end() )
            cout << "Found!\n";
        else
            cout << "not found\n";
    }

    return 0;
}
