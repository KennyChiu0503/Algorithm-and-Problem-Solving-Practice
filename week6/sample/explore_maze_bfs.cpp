#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int maxNM = 1000;

int grid[maxNM][maxNM], n,m;
pair<int,int> fromm[maxNM][maxNM];
int dist[maxNM][maxNM];
int visited[maxNM][maxNM];

int dirs[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

//  return true if (x,y) is valid
//   -- not out of boundary  & walkable
bool is_valid( int x, int y )
{
        return x >= 0 && x < n && y >= 0 && y < m
                && grid[x][y] == 0;
}

//

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

    //

    deque<pii> q;

    dist[s.first][s.second] = 0;
    q.push_back(s);

    while( !q.empty() )
    {
        pii v = q.front();
        q.pop_front();

        for(i=0;i<4;i++)
        {
            int a = v.first + dirs[i][0];
            int b = v.second + dirs[i][1];

            if( is_valid(a,b) && !visited[a][b] )
            {
                visited[a][b] = 1;
                fromm[a][b] = v;
                dist[a][b] = dist[v.first][v.second] + 1;
                q.push_back(pii(a,b));
            }
        }
    }
    //

    cout << (visited[e.first][e.second] ? "YES" : "NO");

    return 0;
}

