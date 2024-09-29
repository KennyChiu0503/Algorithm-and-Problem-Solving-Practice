#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5+1;

int n;
array< array<int,2>, maxN> my_array;

int main()
{
    int i,j,k;

    cin >> n;
    for(i=0;i<n;i++)
        cin >> my_array[i][0] >> my_array[i][1];

    // use iterator to iterate over my_array
    array< array<int,2> ,maxN>::iterator itr = my_array.begin();

    // auto itr = my_array.begin();

    while( itr != my_array.begin()+n )
    {
        cout << '(' << (*itr)[0] << ',' << (*itr)[1] << ')' << "\n";

        itr++;
    }

    // let's do it backward

    for( itr = &my_array[n-1]; itr >= my_array.begin(); itr-- )
        cout << '(' << (*itr)[0] << ',' << (*itr)[1] << ')' << " ";
    cout << "\n";

    return 0;
}
