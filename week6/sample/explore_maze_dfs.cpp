#include <bits/stdc++.h>
using namespace std;

const int maxNM = 1000;

int grid[maxNM][maxNM], n,m;
pair<int,int> fromm[maxNM][maxNM];
int visited[maxNM][maxNM];

int dirs[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

//
//  to explore all unexplored cells reachable from (x,y)
//
void explore( int x, int y )
{
    visited[x][y] = 1;

    for(int i=0; i<4; i++)
    {
        int a = x+dirs[i][0];
        int b = y+dirs[i][1];

        if( a < 0 || a >= n || b < 0 || b >= m )
            continue;

        if( visited[a][b] == 0 )
        {
            fromm[a][b] = pair<int,int>(x,y);
            explore(a,b);
        }
    }
}

int main()
{
    int i,j,k;
    pair<int,int> s, e;

    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        string tmp;
        cin >> tmp;

        for(j=0;j<m;j++)
        {
            grid[i][j] = tmp[j] == '#';
            visited[i][j] = 0;

            if( tmp[j] == 'S' )
                s = pair<int,int>(i,j);
            else if ( tmp[j] == 'E' )
                e = pair<int,int>(i,j);
        }
    }

    explore(s.first, s.second);

    cout << (visited[e.first][e.second] ? "YES" : "NO");

    return 0;
}
