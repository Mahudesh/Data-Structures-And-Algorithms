class Solution {
  public:
    int bellNumber(int n)
    {
        // Code Here
        // vector<vector<int>>dp(n+1, vector<int>dp(n+1));
        vector<vector<int>>dp(n+1, vector<int>(n+1));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                dp[i][0]=dp[i-1][i-1];
                else
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
            
            }
        }
        return dp[n][0];
        
    }
};
