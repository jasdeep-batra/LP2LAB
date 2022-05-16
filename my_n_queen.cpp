#include<bits/stdc++.h>
using namespace std;
//N-Queen
//Idea is: we have got martix...on whichever cell we are placing queen, another queen cannot be places on all
// diagonals row and col associated to that cell.
// so we gotta index all the diagonals slash and backslash type

bool isSafe(int i,int j,vector<vector<int>>& slash, vector<vector<int>>& backslash,vector<int>& slash_check,vector<int>& backslash_check, vector<int>& row_check )
{
    if(slash_check[slash[i][j]] || backslash_check[backslash[i][j]] || row_check[i])
    {
        return false;
    }
    return true;
}
bool solve(vector<vector<int>>& board,int n,int col,vector<vector<int>>& slash, vector<vector<int>>& backslash,vector<int>& slash_check,vector<int>& backslash_check, vector<int>& row_check )
{
    if(col>=n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(i,col,slash,backslash,slash_check,backslash_check,row_check))
        {
            board[i][col] = 1;
            slash_check[slash[i][col]] = 1;
            backslash_check[backslash[i][col]] = 1;
            row_check[i] = 1;
            if(solve(board,n,col+1,slash,backslash,slash_check,backslash_check,row_check))
            {
                return true;
            }
            board[i][col] = 0;
            slash_check[slash[i][col]] = 0;
            backslash_check[backslash[i][col]] = 0;
            row_check[i] = 0;
        }
    }
    return false;
}
void nqueen(vector<vector<int>> board)
{
    int n = board.size();
    vector<vector<int>> slash(n,vector<int>(n,0));
    vector<vector<int>> backslash(n,vector<int>(n,0));
    vector<int> slash_check(2*n-1,0);
    vector<int> backslash_check(2*n-1,0);
    vector<int> row_check(n,0);
    //initilize
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            slash[i][j] = i+j;
            backslash[i][j] = i-j+n-1;
        }
    }
    if (solve(board,n,0,slash,backslash,slash_check,backslash_check,row_check))
    {
        for(auto itr: board)
        {
            for(auto jtr:itr)
            {
                cout<<jtr<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Solution does not exist";
    }
    
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    nqueen(board);
}
