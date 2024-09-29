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

    // print the sorted result
    for( auto it = s.begin(); it != s.end(); it++ )
        cout << *it << ' ';
    cout << '\n';

    //

    return 0;
}
