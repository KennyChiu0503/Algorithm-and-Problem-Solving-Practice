#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5+1;

int A[maxN], n;

//

bool cmp( int a, int b )
{
    return a > b;
}

//

int main()
{
    int i,j,k;

    cin >> n;
    for(i=0; i<n;i++)
        cin >> A[i];

    sort(A,A+n, cmp);

    // sort(A+2,A+4, cmp);

    for(i=0;i<n;i++)
        cout << A[i] << ' ';
    cout << "\n";

    return 0;
}
