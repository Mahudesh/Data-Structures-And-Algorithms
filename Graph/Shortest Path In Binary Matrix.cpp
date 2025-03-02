class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
     {
        int n=grid.size();
        int m=grid[0].size();


        //If Starting Or Ending Has Block
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
        return -1;

        //If There Is Only One Cell And It Is Valid
        if(grid[0][0]==0 && n==1)
        return 1;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});

        vector<vector<int>>dist(n, vector<int>(m,1e9));

        dist[0][0]=0;

        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();

            int dis=todo.first;
            int row=todo.second.first;
            int col=todo.second.second;

            for(int drow=-1;drow<=1;drow++)
            {
                for(int dcol=-1;dcol<=1;dcol++)
                {
                    int nxtRow=row+drow;
                    int nxtCol=col+dcol;
                    //Check For 8 Directional Approach
                    if(nxtRow>=0 && nxtCol>=0 && nxtRow<n && nxtCol<m && grid[nxtRow][nxtCol]==0)
                    {
                        if(nxtRow==n-1 && nxtCol==m-1)
                        return dis+1+1;
                        if(1+dis<dist[nxtRow][nxtCol])
                        {
                            dist[nxtRow][nxtCol]=1+dis;
                            q.push({1+dis,{nxtRow,nxtCol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
