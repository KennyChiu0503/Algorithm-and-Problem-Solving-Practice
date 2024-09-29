#include <bits/stdc++.h>
using namespace std;

const int maxN = (int)1e5+1;

int n;
array<int, maxN> my_array;

int main()
{
    int i,j,k;

    cin >> n;
    for(i=0;i<n;i++)
        cin >> my_array[i];

    // use iterator to iterate over my_array
    array<int,maxN>::iterator itr = my_array.begin();

    // auto itr = my_array.begin();

    while( itr != my_array.begin()+n )
    {
        cout << *itr << "\n";

        itr++;
    }

    // let's do it backward

    for( itr = &my_array[n-1]; itr >= my_array.begin(); itr-- )
        cout << *itr << " ";
    cout << "\n";

    return 0;
}
