#include <bits/stdc++.h>
using namespace std;

map<int,int> s;

int main()
{
    int i,j,k;

    cin >> k;
    while(k--)
    {
        cin >> j;

        if( s.find(j) == s.end() )
            s[j] = 1;
        else
            s[j] ++;
    }

    // print the sorted result
    for( auto it = s.begin(); it != s.end(); it++ )
        for( i = 0; i < it->second; i++ )
            cout << it->first << ' ';
    cout << '\n';

    //

    return 0;
}
