class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]==1)
            {
                dp[0][j]=1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==1)
            {
                dp[i][0]=1;
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }

        for(auto it1: dp)
        {
            for(auto it2: it1)
            cnt=cnt+it2;
        }

        return cnt;
    }
};
