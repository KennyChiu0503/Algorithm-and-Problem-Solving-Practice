#include <bits/stdc++.h>
using namespace std;

const int maxN = 10;

int n;
int A[maxN];    // for recording the result, 1 iff selected

void gen_subsets( int level )
{
    int i,j,k;

    if( level == n )
    {
        // All the decisions are made,
        // print the result.

        for(i=0,j=0;i<n;i++)
        {
            if( A[i] )
            {
                if( j )
                    cout << ", ";

                cout << i+1;

                j = 1;
            }
        }
        if( j == 0 )
            cout << "empty";

        cout << "\n";

        return;
    }

    // Recurse on two different cases
    //  to generate all possible results
    A[level] = 0;
    gen_subsets(level+1);

    A[level] = 1;
    gen_subsets(level+1);
}

int main()
{
    cin >> n;

    gen_subsets(0);

    return 0;
}
