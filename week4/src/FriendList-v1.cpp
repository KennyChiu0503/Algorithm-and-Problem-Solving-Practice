#include <bits/stdc++.h>
using namespace std;

map<string,int> name2idx;
vector<string> idx2name;

vector<set<int>> lsts;

int main()
{
    int i,j,k;
    string s1,s2,s3;

    cin >> k;
    for(i=0;i<k;i++)
    {
        cin >> s1;

        name2idx[s1] = i;
        idx2name.push_back(s1);
        lsts.push_back(set<int>());
    }

    cin >> k;
    while(k--)
    {
        cin >> s1 >> s2;

        if( s1 == "MakeFriend" )
        {
            cin >> s3;

            i = name2idx[s2];
            j = name2idx[s3];

            lsts[i].insert(j);
            lsts[j].insert(i);
        }
        else
        {
            k = name2idx[s2];
            for(auto it = lsts[k].begin(); it != lsts[k].end(); it++ )
                cout << idx2name[*it] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
