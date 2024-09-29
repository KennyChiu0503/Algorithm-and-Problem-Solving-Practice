#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main()
{
    int i,j,k;

    cin >> k;
    while(k--)
    {
        cin >> j;

        A.push_back(j);
    }

    sort(A.begin(), A.end());

    //

    cin >> k;
    while(k--)
    {
        cin >> j;

        auto it = lower_bound(A.begin(),A.end(),j);

        if( it == A.end() || *it != j )
            cout << "not found\n";
        else
            cout << "Found!\n";
    }

    return 0;
}
