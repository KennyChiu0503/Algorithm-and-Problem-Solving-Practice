#include <bits/stdc++.h>
using namespace std;

//  ch, eng, math, sci, soc, exceptional, total, idx
typedef array<int,8> grade;

vector<grade> grades;

// compare object for grade
struct grade_cmp
{
    bool operator() ( const grade &a, const grade &b ) const
    {
        if( a[5] != b[5] )
            return a[5];

        if( a[6] != b[6] )
            return a[6] > b[6];

        for(int i=0;i<5;i++)
            if( a[i] != b[i] )
                return a[i] > b[i];
    }
};

int main()
{
    int i,j,k;

    //
    //  read input and pre-process
    //
    cin >> k;
    for(j=0;j<k;j++)
    {
        //  ch, eng, math, sci, soc, exceptional, total, idx
        grade tmp;

        tmp[5] = 1;
        tmp[6] = 0;
        tmp[7] = j;
        for(i=0;i<5;i++)
        {
            cin >> tmp[i];

            if( tmp[i] < 90 )
                tmp[5] = 0;

            tmp[6] += tmp[i];
        }

        grades.push_back(tmp);
    }

    //

    sort( grades.begin(), grades.end(), grade_cmp() );

    //

    vector<int> r;
    r.resize(grades.size());

    k = 1;
    for( auto it = grades.begin(); it != grades.end(); it++ )
    {
        /*
        for(i=0;i<5;i++)
            cout << (*it)[i] << ' ';
        cout << '\n';
        */

        r[(*it)[7]] = k++;
    }

    for(i=0;i<r.size();i++)
        cout << r[i] << ' ';
    cout << '\n';

    //

    return 0;
}
