class Solution {
public:
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    visited[row][col]=true;
    for(int d=0;d<4;d++)
    {
        int nxtRow=row+dx[d];
        int nxtCol=col+dy[d];
        if(nxtRow>=0 && nxtCol>=0 && nxtRow<n && nxtCol<m &&!visited[nxtRow][nxtCol] && mat[nxtRow][nxtCol]=='O')
        {
            visited[nxtRow][nxtCol]=true;
            dfs(nxtRow,nxtCol,visited,mat);
        }
    }


}
    void solve(vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int j=0;j<m;j++)
        {
            //Traverse For First Row
            if(!visited[0][j] && board[0][j]=='O')
            dfs(0,j,visited,board);

            //Traverse For Last Row
            if(!visited[n-1][j] && board[n-1][j]=='O')
            dfs(n-1,j,visited,board);
        }
        for(int i=0;i<n;i++)
        {
            //Traverse For First Column
            if(!visited[i][0] && board[i][0]=='O')
            dfs(i,0,visited,board);

            //Traverse For Last Column
            if(!visited[i][m-1] && board[i][m-1]=='O')
            dfs(i,m-1,visited,board);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }

    }
};
