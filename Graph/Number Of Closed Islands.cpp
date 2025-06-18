class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

// First Exclude The Zeros Reaching Boundaries
// Find The Number Of Connected Components Using 0s
void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& grid)
{
    visited[r][c]=true;

    for(int d=0;d<4;d++)
    {
        int nxtrow=r+dx[d];
        int nxtcol=c+dy[d];
        if(nxtrow>=0 && nxtcol>=0 && nxtrow<grid.size() && nxtcol<grid[0].size() && !visited[nxtrow][nxtcol] && grid[nxtrow][nxtcol]==0)
        {
            dfs(nxtrow,nxtcol,visited,grid);
        }
    }
}
    int closedIsland(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        int island=0;
       for(int j=0;j<m;j++)
       {
        if(!visited[0][j] && grid[0][j]==0)
        {
            dfs(0,j,visited,grid);
        }
        if(!visited[n-1][j] && grid[n-1][j]==0)
        {
            dfs(n-1,j,visited,grid);
        }
       }

       for(int i=0;i<n;i++)
       {
            if(!visited[i][0] && grid[i][0]==0)
            {
                dfs(i,0,visited,grid);
            }
            if(!visited[i][m-1] && grid[i][m-1]==0)
            {
                dfs(i,m-1,visited,grid);
            }
       }

       for(int i=1;i<n-1;i++)
       {
        for(int j=1;j<m-1;j++)
        {
            if(!visited[i][j] && grid[i][j]==0)
            {
                dfs(i,j,visited,grid);
                island++;
            }
        }
       }
       return island;
    }
};
