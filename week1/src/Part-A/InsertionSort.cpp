#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)2e7;

// array for input numbers
int A[maxN], n;

int main()
{
    int i,j,k;

    freopen("random_num.in", "r", stdin);

    cin >> n;
    for(i=0; i<n; i++)
        cin >> A[i];

    // perform Insertion Sort
    for(i=0; i<n; i++)
    {
        int key = A[i];

        // A[0... i-1] are sorted
        for(j=i-1; j>=0 && A[j] > key; j--)
            A[j+1] = A[j];

        A[j+1] = key;
    }

    for(i=0;i<n;i++)
        cout << A[i] << ' ';
    cout << "\n";

    return 0;
}
