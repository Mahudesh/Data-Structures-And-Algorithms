#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m)
{
    // Write your code here.
    vector<vector<int>>ans(n, vector<int>(m,INT_MAX));
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                ans[i][j]=0;
                q.push({0,{i,j}});
                visited[i][j]=true;
            }
            if(a[i][j]==-1)
            ans[i][j]=-1;
        }
    }
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    while(!q.empty())
    {
        auto todo=q.front();
        q.pop();
        int steps=todo.first;
        int r=todo.second.first;
        int c=todo.second.second;
        ans[r][c]=min(ans[r][c],steps);
        for(int d=0;d<4;d++)
        {
            int nxtrow=r+dx[d];
            int nxtcol=c+dy[d];
            if(nxtrow>=0 && nxtcol>=0 && nxtrow<n && nxtcol<m && !visited[nxtrow][nxtcol] && a[nxtrow][nxtcol]==INT_MAX)
            {
                visited[nxtrow][nxtcol]=true;
                q.push({steps+1,{nxtrow,nxtcol}});
            }
        }
    }
    return ans;
}
