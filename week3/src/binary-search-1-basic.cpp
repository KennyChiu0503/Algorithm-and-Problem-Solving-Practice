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

        int left = -1, right = A.size();

        while( left < right-1 )
        {
            int mid = (left+right)/2;

            if( A[mid] < j )
                left = mid;
            else
                right = mid;
        }

        if( right == A.size() || A[right] != j )
            cout << "not found\n";
        else
            cout << "Found!\n";
    }

    return 0;
}
