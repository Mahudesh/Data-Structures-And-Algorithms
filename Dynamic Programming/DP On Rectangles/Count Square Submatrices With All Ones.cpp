int countSquares(int n, int m, vector<vector<int>> &arr) 
{
    vector<vector<int>>dp(n, vector<int>(m,0));

    for(int j=0;j<m;j++)
    {
        dp[0][j]=arr[0][j];
    }
    for(int i=0;i<n;i++)
    {
        dp[i][0]=arr[i][0];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==1)
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cnt=cnt+dp[i][j];
    }
    return cnt;
}
