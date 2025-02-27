class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        vector<vector<int>>dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=true;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            auto todo=q.front();
            q.pop();
            int row=todo.first.first;
            int col=todo.first.second;
            int steps=todo.second;
            dist[row][col]=steps;

            for(int d=0;d<4;d++)
            {
                int nxtRow=row+dx[d];
                int nxtCol=col+dy[d];
                if(nxtRow>=0 && nxtRow<n && nxtCol>=0 && nxtCol<m && !visited[nxtRow][nxtCol])
                {
                    visited[nxtRow][nxtCol]=true;
                    q.push({{nxtRow,nxtCol},steps+1});
                }
            }
        }
        return dist;
    }
};
