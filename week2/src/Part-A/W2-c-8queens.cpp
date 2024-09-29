#include <bits/stdc++.h>
using namespace std;

//
// 0 if valid, 1 if reserved
// 2 if a queen is placed
//
array< array<int,8>, 8> board;

//
//  return true iff placing a queen at [r][c] is valid
//
bool is_valid( int r, int c )
{
    int i,j,k;

    if( board[r][c] )
        return false;

    // check row
    for(j=0;j<8;j++)
        if( j != c && board[r][j] == 2 )
            return false;

    // check column
    for(i=0;i<8;i++)
        if( i != r && board[i][c] == 2 )
            return false;

    // check diagonals
    for(i=1;i<8;i++)
    {
        if( r+i < 8 && c+i < 8 && board[r+i][c+i] == 2 )
            return false;

        if( r-i >= 0 && c+i < 8 && board[r-i][c+i] == 2 )
            return false;

        if( r+i < 8 && c-i >= 0 && board[r+i][c-i] == 2 )
            return false;

        if( r-i >= 0 && c-i >= 0 && board[r-i][c-i] == 2 )
            return false;
    }

    // if all the above tests are passed, it is valid
    return true;
}

int cnt( int row )
{
    int i,j,k;

    if( row == 8 )
    {
        // a valid placement is found
        return 1;
    }

    k = 0;

    for(i=0;i<8;i++)
    {
        // if [row][i] is valid, then place it and recurse.
        if( is_valid(row,i) )
        {
            board[row][i] = 2;

            k += cnt( row+1 );

            board[row][i] = 0;
        }
    }

    return k;
}

int main()
{
    int i,j,k;
    string tmp;

    for(i=0;i<8;i++)
    {
        cin >> tmp;
        for(j=0;j<8;j++)
            board[i][j] = (tmp[j]=='.') ? 0 : 1;
    }

    cout << cnt(0) << "\n";

    return 0;
}
