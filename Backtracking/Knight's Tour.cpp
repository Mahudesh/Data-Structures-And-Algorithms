#include<bits/stdc++.h>
using namespace std;
const int dx[8]={2,1,-1,-2,-2,-1,1,2};
const int dy[8]={1,2,2,1,-1,-2,-2,-1};
bool isSafe(int r, int c, int n)
{
    return r>=0 && c>=0 && r<n && c<n;
}
bool helper(int n, vector<vector<int>>& board, int pos, int r, int c)
{
    if(pos==n*n)
    return true;
    
    for(int i=0;i<8;i++)
    {
        int nxtrow=r+dx[i];
        int nxtcol=c+dy[i];
        if(isSafe(nxtrow,nxtcol,n) && board[nxtrow][nxtcol]==-1)
        {
            board[nxtrow][nxtcol]=pos;
            if(helper(n,board,pos+1,nxtrow,nxtcol))
            return true;
            board[nxtrow][nxtcol]=-1;
        }
        // return false;
    }
    return false;
}

int main()
{
    int n=8;
    // cin>>n;
    vector<vector<int>>board(n, vector<int>(n,-1));
    board[0][0]=0;
    if(helper(n,board,1,0,0))
    {
        for(auto it1 : board)
        {
            for(auto it2 : it1)
            cout<<it2<<" ";
            cout<<endl;
        }
    }
}
