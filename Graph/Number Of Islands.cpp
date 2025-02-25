#include <bits/stdc++.h>
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
    visited[i][j]=true;

    for(int drow=-1;drow<=1;drow++)
    {
        for(int dcol=-1;dcol<=1;dcol++)
        {
            int nxtRow=i+drow;
            int nxtCol=j+dcol;
            if(nxtRow>=0 && nxtCol>=0 && nxtRow<grid.size() && nxtCol<grid[0].size() && !visited[nxtRow][nxtCol] && grid[nxtRow][nxtCol]==1)
            {
                dfs(nxtRow,nxtCol,grid,visited);
            }
        }
    }
}
// void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
// {
//     queue<pair<int,int>>q;
//     q.push({i,j});
//     visited[i][j]=true;

//     while(!q.empty())
//     {
//         auto todo=q.front();
//         q.pop();
//         i=todo.first;
//         j=todo.second;

//         visited[i][j]=true;

//         for(int drow=-1;drow<=1;drow++)
//         {
//             for(int dcol=-1;dcol<=1;dcol++)
//             {
//                   int nxtRow=i+drow;
//                   int nxtCol=j+dcol;
//                 if(nxtRow>=0 && nxtRow<grid.size() && nxtCol>=0 && nxtCol<grid[0].size() && !visited[nxtRow][nxtCol] && grid[nxtRow][nxtCol]==1)
//                 {
//                 q.push({nxtRow,nxtCol});
//                 visited[nxtRow][nxtCol]=true;
//                 }
//             }
//         }

//     }
// } 
int numberOfIslands(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here
    int cnt=0;
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && grid[i][j]==1)
            {
                cnt++;
                dfs(i,j,grid,visited);
            }
        }
    }
    return cnt;
}
