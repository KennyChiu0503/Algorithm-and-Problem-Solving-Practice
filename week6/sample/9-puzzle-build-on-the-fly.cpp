#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//

struct node;
map<ll,node*> enc2node; // find node by enc

//

struct node {
    int board[3][3];
    ll enc;  // an encoding used for comparison

    int dist; // its distance to the starting board
    node *fromm;

    vector<node*> adj;

    // compute adj of this node
    // generate the node if not exists yet
    void find_adj()
    {
        int i,j,k;
        int a,b,c;
        int tmp[3][3];

        int dirs[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                tmp[i][j] = board[i][j];

        // find 0
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                if( tmp[i][j] == 0 )
                    break;
            if( j<3 )
                break;
        }

        for(a=0;a<4;a++)
        {
            b = i+dirs[a][0];
            c = j+dirs[a][1];

            if( b < 0 || b > 2 || c < 0 || c > 2 )
                continue;

            swap(tmp[i][j], tmp[b][c]);

            ll enc = encoding(tmp);
            auto it = enc2node.find(enc);

            if( it == enc2node.end() )
            {
                node *nde = new node(tmp);
                enc2node[enc] = nde;
                adj.push_back(nde);
            }
            else
                adj.push_back(it->second);

            swap(tmp[i][j], tmp[b][c]);
        }
    }

    // return the encoding of a board
    static long long encoding( int board[3][3] )
    {
        long long ans = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ans = ans * 10 + board[i][j];
        return ans;
    }

    node( int board[3][3] )
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                this->board[i][j] = board[i][j];

        enc = encoding(board);
        dist = -1;  // not visited yet
        fromm = NULL;
    }

    bool operator < ( struct node const &target_node ) const
    {
        return enc < target_node.enc;
    }
};

//

void BFS( ll s, ll t )
{
    deque<node*>  q;

    q.push_back(enc2node[s]);
    q.front()->dist = 0;
    q.front()->fromm = NULL;

    while( !q.empty() )
    {
        node *v = q.front();
        q.pop_front();

        v->find_adj();
        for(int k = 0; k < v->adj.size(); k++)
        {
            if( v->adj[k]->dist == -1 ) // not explored yet
            {
                v->adj[k]->dist = v->dist+1;
                v->adj[k]->fromm = v;
                q.push_back(v->adj[k]);

                if( v->adj[k]->enc == t )
                    return;
            }
        }
    }
}

//

void print_result( node *t )
{
    if( t == NULL )
        return;

    print_result(t->fromm);

    cout << "----------\n";

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << t->board[i][j] << ' ';
        cout << '\n';
    }
}

//
// ex.
// 1 0 3
// 4 5 6
// 7 8 2
//

int main()
{
    int i,j,k;
    int board[3][3], used[9];

    for(i=0;i<9;i++)
        used[i] = 0;

    //

    // read starting board
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin >> board[i][j];
    ll s = node::encoding(board);

    enc2node[s] = new node(board);

    // target board
    for(i=0,k=0;i<3;i++)
        for(j=0;j<3;j++)
            board[i][j] = ++k;
    board[2][2] = 0;
    ll t = node::encoding(board);

    BFS(s,t);

    auto it = enc2node.find(t);

    if( it == enc2node.end() )
        cout << "Not possible\n";
    else
        print_result(it->second);

    return 0;
}
