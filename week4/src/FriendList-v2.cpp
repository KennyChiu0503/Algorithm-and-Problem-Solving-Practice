#include <bits/stdc++.h>
using namespace std;

typedef set<string> f_list;
map<string, f_list> ppl;

int main()
{
    int i,j,k;
    string s1, s2, s3;

    cin >> k;
    while(k--)
    {
        cin >> s1;
        ppl[s1] = f_list();
    }

    cin >> k;
    while(k--)
    {
        cin >> s1 >> s2;

        if( s1 == "MakeFriend" )
        {
            cin >> s3;

            ppl[s2].insert(s3);
            ppl[s3].insert(s2);
        }
        else
        {
            // save this reference to be used repeatedly later
            // important!
            auto &lst = ppl[s2];

            for( auto it = lst.begin(); it != lst.end(); it++ )
                cout << *it << ' ';
            cout << '\n';
        }
    }

    return 0;
}
