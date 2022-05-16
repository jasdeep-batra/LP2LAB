#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>>& board, int row, int col)
{
    for(int i=row;i>=0;i--)
    {
        if(board[i][col]== 1)return false;
    }
    for(int j=col;j>=0;j--)
    {
        if(board[row][j]== 1)return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(board[i][j]==1)return false;
    }
    for(int i=row,j=col;i<board.size()&&j>=0;i++,j--)
    {
        if(board[i][j]==1)return false;
    }
    return true;
}
bool nqueen(vector<vector<int>>& board, int n, int col)
{
    if(col>=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        if(issafe(board,i,col))
        {
            board[i][col] = 1;
            if(nqueen(board,n,col+1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    nqueen(board,n,0);
    for(auto i: board)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}