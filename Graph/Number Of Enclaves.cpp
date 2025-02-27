class Solution {
public:
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int row, int col, vector<vector<bool>> &visited, vector<vector<int>>& grid)
{
    visited[row][col]=true;
    int n=grid.size();
    int m=grid[0].size();

    for(int d=0;d<4;d++)
    {
        int nxtRow=row+dx[d];
        int nxtCol=col+dy[d];

        if(nxtRow>=0 && nxtCol>=0 && nxtRow<n && nxtCol<m && !visited[nxtRow][nxtCol] && grid[nxtRow][nxtCol]==1)
        {
            dfs(nxtRow,nxtCol,visited,grid);
        }
    }


}
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int j=0;j<m;j++)
        {
            if(!visited[0][j] && grid[0][j]==1)
            dfs(0,j,visited,grid);

            if(!visited[n-1][j] && grid[n-1][j]==1)
            dfs(n-1,j,visited,grid);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && grid[i][0]==1)
            dfs(i,0,visited,grid);

            if(!visited[i][m-1] && grid[i][m-1]==1)
            dfs(i,m-1,visited,grid);
        }
        int enclaves=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                enclaves++;
            }
        }
        return enclaves;
    }
};
