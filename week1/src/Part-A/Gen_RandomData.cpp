#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;

    freopen("random_num.in", "w", stdout);

    srand(time(NULL));

    cin >> k;

    cout << k << "\n";
    while(k--)
        cout << rand() << ' ';
    cout << "\n";

    fclose(stdout);

    return 0;
}
