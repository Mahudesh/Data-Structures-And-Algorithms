class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited)
{
    visited[r][c]=true;
    for(int d=0;d<4;d++)
    {
        int nxtrow=r+dx[d];
        int nxtcol=c+dy[d];

        if(nxtrow>=0 && nxtcol>=0 && nxtrow<heights.size() && nxtcol<heights[0].size() && !visited[nxtrow][nxtcol])
        {
            if(heights[r][c]<=heights[nxtrow][nxtcol])
            {
                dfs(nxtrow,nxtcol,heights,visited);
            }   
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>pacific(n, vector<bool>(m,false));
        vector<vector<bool>>atlantic(n, vector<bool>(m,false));

        for(int j=0;j<m;j++)
        {
            if(!pacific[0][j])
            {
                dfs(0,j,heights,pacific);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!pacific[i][0])
            {
                dfs(i,0,heights,pacific);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!atlantic[i][m-1])
            {
                dfs(i,m-1,heights,atlantic);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!atlantic[n-1][j])
            {
                dfs(n-1,j,heights,atlantic);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
